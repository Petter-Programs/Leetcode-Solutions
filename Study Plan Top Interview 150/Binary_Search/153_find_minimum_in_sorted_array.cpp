class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size()-1;
        int min = INT_MAX;

        while(left <= right)
        {
            int middle = left + (right-left)/2;

            // Sorted part must be on left side
            if(nums[left] <= nums[middle])
            {
                min = std::min(min, nums[left]);
                left = middle+1;
            }

            // Sorted part must be on right side
            else
            {
                min = std::min(min, nums[middle]);
                right = middle-1;
            }
        }

        return min;
        
    }
};