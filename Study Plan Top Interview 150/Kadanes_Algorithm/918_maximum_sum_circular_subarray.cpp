class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;

        int curr_sum_min = 0;
        int curr_sum_max = 0;

        int arr_sum = 0;

        for(int number : nums)
        {
            arr_sum += number;

            if(curr_sum_max + number > 0)
            {
                curr_sum_max+=number;
                max_sum = std::max(curr_sum_max, max_sum);
            }
            else
            {
                curr_sum_max = 0;
                max_sum = std::max(max_sum, number);
            }

            if(curr_sum_min + number < 0)
            {
                curr_sum_min += number;
                min_sum = std::min(curr_sum_min, min_sum);
            }
            else if(number < 0)
            {
                curr_sum_min = number;
                min_sum = std::min(curr_sum_min, min_sum);
            }
            else
            {
                curr_sum_min = 0;
            }
        }

        if(max_sum < 0)
        {
            return max_sum;
        }

        return std::max(max_sum, arr_sum-min_sum);
        
    }
};