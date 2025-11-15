class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        std::vector<int> ans;
        int left = 0;
        int right = nums.size()-1;

        int start_idx = -1;

        // find left bound
        while(left <= right)
        {
            int middle = left + (right-left) / 2;
            
            if(nums[middle] == target)
            {
                right = middle-1;
                start_idx = middle;
            }

            else if(nums[middle] > target)
            {
                right = middle-1;
            }

            else
            {
                left = middle+1;
            }
        }

        int end_idx = -1;

        if(start_idx >= 0)
        {
            left = 0;
            right = nums.size()-1;
            
            while(left <= right)
            {
                int middle = left + (right-left) / 2;
                
                if(nums[middle] == target)
                {
                    left = middle+1;
                    end_idx = middle;
                }

                else if(nums[middle] > target)
                {
                    right = middle-1;
                }

                else
                {
                    left = middle+1;
                }
            }
        }

        ans.push_back(start_idx);
        ans.push_back(end_idx);

        return ans;
    }
};