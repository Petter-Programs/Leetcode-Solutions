class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {   
        // at each step:
        // look back in the array to pick max(size) where val > min; increment it

        std::vector<int> vec;

        int best_steps_seen = 1;

        for(int i = 0; i < nums.size(); ++i)
        {
            int best_steps = 1;

            int min_at_step = nums[i];

            for(int j = 0; j<vec.size(); ++j)
            {
                int curr_steps = vec[j];
                int curr_min = nums[j];

                if(min_at_step > curr_min)
                {
                    best_steps = std::max(curr_steps+1, best_steps);
                }

            }

            vec.push_back(best_steps);
            best_steps_seen = std::max(best_steps, best_steps_seen);
        }

        return best_steps_seen;
    }
};