#define VISITING -1
#define VISITED -2

class Solution {
private:
    bool try_complete(int course, vector<vector<int>>& courses, vector<int>& result, std::vector<int>& in_solution)
    {
        if(in_solution[course] == VISITED)
        {
            return true;
        }

        if(in_solution[course] == VISITING)
        {
            return false;
        }
        
        // std::cout << "visting " << course << std::endl;

        in_solution[course] = VISITING;

        if(courses[course].size() > 0)
        {
            for(auto dep_course : courses[course])
            {
                if(!try_complete(dep_course, courses, result, in_solution))
                {
                    return false;
                }
            }

        }

        in_solution[course] = VISITED;

        result.push_back(course);

        return true;

    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> result;

        vector<vector<int>> course_list(numCourses);

        std::vector<int> in_solution(numCourses);

        for(auto prereq : prerequisites)
        {
            auto course = prereq[0];
            auto dependency = prereq[1];

            course_list[course].push_back(dependency);
        }

        // need to find a valid order through the prerequisites
        // there may be disjoint orderings

        // can we go through the courses and just see if we can complete each
        // if already completed: ok, ignore
        // if no prereqs: add to result vector
        // if any prereqs: try to complete them first. add resulting sequence to result, or reject

        for(int idx = 0; idx<course_list.size(); ++idx)
        {
            if(in_solution[idx] == VISITED)
            {
                continue;
            }

            if(course_list[idx].size() == 0)
            {
                result.push_back(idx);
                in_solution[idx] = VISITED;
            }
            else
            {
                if(!try_complete(idx, course_list, result, in_solution))
                {
                    return std::vector<int>();
                }
            }
        }

        return result;
    }
};