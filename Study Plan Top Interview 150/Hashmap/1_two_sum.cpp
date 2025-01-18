class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::map<int, int> the_map;
        vector<int> answer;

        int idx = 0;
        for(auto it = nums.begin(); it != nums.end(); ++it)
        {
            int would_need_for_target = target-*it;
            if(the_map.find(would_need_for_target) != the_map.end())
            {
                answer.push_back(the_map.find(would_need_for_target)->second);
                answer.push_back(idx);
                return answer;   
            }
            the_map[*it] = idx; 
            ++idx;
        }

        return answer;

    }
};
