class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int start_idx = 0;
        int end_idx = nums.size();
        int middle = (start_idx + end_idx)/2;
        
        while(start_idx<end_idx && nums[middle] != target)
        {
            if(nums[middle] > target)
            {
                end_idx = middle;
            }
            else
            {
                start_idx = middle+1;
            }
            
            middle = (start_idx + end_idx)/2;
        }

        return middle;
        
    }
};