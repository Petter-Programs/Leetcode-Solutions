#define VISITED -1
#define CONFIRMED_NO_LOOP -200

struct Course
{
    int prereq_no;
    vector<struct Course*> prereq_list;
};

class Solution {
private:
    bool has_dependency_loops(struct Course *the_course)
    {
        auto the_prereq = the_course->prereq_no;
        the_course->prereq_no = VISITED;

        for(auto prereq : the_course->prereq_list)
        {
            if(prereq->prereq_no == CONFIRMED_NO_LOOP)
            {
                continue;
            }
            else if(prereq->prereq_no == VISITED || has_dependency_loops(prereq))
            {
                return true;
            }
        }
        the_course->prereq_no = CONFIRMED_NO_LOOP;

        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // if mapping exists a->b and try to add b->a then can not finish
        // we don't have to do the courses in numerical order, can do 1 before 0
        // intuitively seems like the only condition should be if we have no loops
        // but maybe the loops can be longer?
        // [1->2] [2->3] [3->1] --> loop
        // so we can map only the prerequisites
        // then detect loops as we traverse

        if(prerequisites.size() == 0)
        {
            return true;
        }

        std::unordered_map<int, struct Course> dependency_map;

        for(auto pre : prerequisites)
        {
            auto curr_course = pre[0];
            auto depend_course = pre[1];

            dependency_map[curr_course].prereq_no = curr_course;
            dependency_map[depend_course].prereq_no = depend_course;

            dependency_map[curr_course].prereq_list.push_back(&dependency_map[depend_course]);
        }

        // we can end up at a point in the graph many times without necessarily looping
        // 1->2->3->4, 5->3

        for(auto dep : dependency_map)
        {
            if(dep.second.prereq_no == CONFIRMED_NO_LOOP)
            {
                continue;
            }

            if(has_dependency_loops(&dep.second))
            {
                return false;
            }
        }

        return true;        
    }
};