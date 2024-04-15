
int minSubArrayLen(int target, int* nums, int numsSize) 
{
    // Intuition: all numbers are positive, so can reuse sums found

    int left = 0;
    int right = 1;
    int min_win = INT_MAX;
    int curr_win = 1;

    int sum = nums[left];

    while(left<numsSize)
    {
        // Current subarray does not meet constraint
        if(sum < target)
        {

            // We cannot expand the window further, so we are done
            if(right>=numsSize)
                break;

            sum+=nums[right];
            right++;
            curr_win++;
        }

        // Current subarray does meet constraint
        else if(sum>=target)
        {
            // Smallest window we've found
            if(curr_win<min_win)
                min_win = curr_win;

            // Shrink window further
            sum-=nums[left];

            left++;
            if(right<left)
            {
                right = left+1;
                sum = nums[left];
                curr_win = 1;
            }
            else
                curr_win--;            
        }
    }

    return min_win == INT_MAX ? 0 : min_win;
}
