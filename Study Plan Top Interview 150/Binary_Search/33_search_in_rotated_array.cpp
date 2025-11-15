class Solution {
private:
    bool is_a_start(vector<int>& nums, int idx)
    {
        int left_val = idx > 0 ? nums[idx-1] : INT_MAX;
        int right_val = idx < nums.size()-1 ? nums[idx+1] : INT_MAX;

        return nums[idx] < left_val && nums[idx] < right_val;
    }

    int find_k(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right)
        {
            int middle = (left+right) / 2;

            if(is_a_start(nums, middle))
            {
                return middle;
            }

            if(nums[middle] >= nums[0])
            {
                left = middle+1;
            }
            else
            {
                right = middle-1;
            }
        }

        // looks like nums was well-ordered
        return 0;
    }

public:
    int search(vector<int>& nums, int target) 
    {
        // first pass: identify the sorted start
        // then can have a concept of sorted-left and sorted-right pointers
        // w/ conversion function to real idx

        int k = find_k(nums);

        int left = 0;
        int right = nums.size()-1;

        while(left <= right)
        {
            int middle = (left+right)/2;
            int middle_num = nums[(middle+k)%nums.size()];

            if(middle_num == target)
            {
                return (middle+k)%nums.size();
            }

            else if(middle_num > target)
            {
                right = middle-1;
            }
            else
            {
                left = middle+1;
            }

        }
        
        return -1;
        
    }
};