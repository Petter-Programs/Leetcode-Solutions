class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        for(int i : nums)
        {
            if((curr_sum + i) > 0) 
            {
                curr_sum += i;
                max_sum = std::max(max_sum, curr_sum);
            }

            else
            {
                curr_sum = 0;
                max_sum = std::max(max_sum, i);
            }

        }

        return max_sum;
        
    }
};