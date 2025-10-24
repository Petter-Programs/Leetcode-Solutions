class Solution {
private:
    bool is_peak(vector<int>& nums, int idx, bool& bigger_than_prev, bool& bigger_than_next)
    {
        int num = nums[idx];
        bigger_than_prev = idx > 0 ? (num > nums[idx-1]) : true;
        bigger_than_next = idx < nums.size()-1 ? (num > nums[idx+1]) : true;
        return bigger_than_prev && bigger_than_next;
    }
public:
    int findPeakElement(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right)
        {
            int middle = (left+right)/2;
            bool bigger_than_prev, bigger_than_next;
            
            bool peak = is_peak(nums, middle, bigger_than_prev, bigger_than_next);

            if(peak)
                return middle;

            if(!bigger_than_next)
            {
                left = middle+1;
            }

            else
            {
                right = middle-1;
            }
        }

        return 0;


    }
};