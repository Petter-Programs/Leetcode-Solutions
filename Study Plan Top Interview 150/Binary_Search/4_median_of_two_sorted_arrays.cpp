class Solution {
private:
    double get_median(std::vector<int>& nums)
    {
        if(nums.size()%2 != 0)
            return nums[nums.size()/2];

        else
        {
            int idx_start = nums.size()/2 - 1;
            int idx_end = nums.size()/2;
            return (nums[idx_start] + nums[idx_end])/2.0;
        }
    }

    void get_indices(vector<int>& long_nums, vector<int>& short_nums, int half_size,
    int& first_half_short_end, int& first_half_long_end)
     {
        int start = 0;
        int end = short_nums.size() >= half_size ? half_size : short_nums.size();

        while(start <= end)
        {
            int short_guess_end = start + (end-start)/2;

            int long_guess_end = half_size-short_guess_end;

            int curr_val_short = short_guess_end > 0 ? short_nums[short_guess_end-1] : INT_MIN;
            int curr_val_long = long_guess_end > 0 ? long_nums[long_guess_end-1] : INT_MIN;

            int next_value_short = short_guess_end <= short_nums.size() - 1 ? short_nums[short_guess_end] : INT_MAX;
            int next_value_long = long_guess_end <= long_nums.size()-1 ? long_nums[long_guess_end] : INT_MAX;

            if(curr_val_short <= next_value_long
            && curr_val_long <= next_value_short)
            {
                // We found it!
                first_half_short_end = short_guess_end;
                first_half_long_end = long_guess_end;

                 return;
            }

           // We need to reduce the number of included values in the shorter list
           if(curr_val_short > next_value_long)
           {
                end = short_guess_end;
           }

           // We need to increase the number of included values in the shorter list
           else
           {
                start = short_guess_end+1;
           }
        }

     }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() == 0) 
            return get_median(nums2);
        else if(nums2.size() == 0)
            return get_median(nums1);

        std::reference_wrapper<std::vector<int>> shorter_nums = nums2;
        std::reference_wrapper<std::vector<int>> longer_nums = nums1;

        if(nums2.size() > nums1.size())
        {
            shorter_nums = nums1;
            longer_nums = nums2;
        }

        int combined_sizes = nums1.size() + nums2.size();
        
        // 1 2 3
        // --> 1, median is right after
        // 1 2 3 4
        // --> 2, median is avg of last plus right after
        int half_numbers = combined_sizes/2;

        int first_half_short_end, first_half_long_end;
        
        get_indices(longer_nums.get(), shorter_nums.get(), half_numbers, first_half_short_end, first_half_long_end);

        int left_side_shorter = first_half_short_end > 0 ? 
                                shorter_nums.get()[first_half_short_end-1] : INT_MIN;

        int left_side_longer = first_half_long_end > 0 ? 
                                longer_nums.get()[first_half_long_end-1] : INT_MIN;

        int right_side_shorter = first_half_short_end <= shorter_nums.get().size()-1 ? 
                                shorter_nums.get()[first_half_short_end] : INT_MAX;

        int right_side_longer = first_half_long_end <= longer_nums.get().size() - 1 ? 
                                longer_nums.get()[first_half_long_end] : INT_MAX;

        if(combined_sizes % 2 == 0)
        {
            // max of left side, min of right side
            return (std::max(left_side_shorter, left_side_longer)
                    + std::min(right_side_shorter, right_side_longer)) / 2.0;
        }

        else
        {
            return std::min(right_side_shorter, right_side_longer);
        }

    }
};