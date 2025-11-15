int search(int* nums, int numsSize, int target) 
{
    int left = 0;
    int right = numsSize-1;

    while(left <= right)
    {
        int middle = left + (right-left) / 2;

        if(nums[middle] == target)
        {
            return middle;
        }

        if(nums[left] <= nums[middle])
        {
            // From left pointer to middle pointer, we know we have a sorted array

            // since we know the section is sorted, if it is less than the min, it cannot be there
            // conversely if greater than this sorted area's biggest, it cannot be there either
            if(target < nums[left] || target > nums[middle])
                left = middle+1;
            
            // Target is within the bounds of the sorted area, must be somewhere there
            else
                right = middle-1;
        }

        else
        {
            // We know we do NOT have a sorted array in the left half,
            // so knowing that we have a single point that breaks the
            // sorted condition, we can deduce that the right half is sorted

            // Target is outside of the boundaries of this sorted section
            if(target < nums[middle] || target > nums[right])
                right = middle-1;

            // Target is inside the boundaries of this sorted section
            else
                left = middle+1;

        }

    }   

    return -1;
}