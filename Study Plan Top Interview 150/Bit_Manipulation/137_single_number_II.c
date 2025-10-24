int singleNumber(int* nums, int numsSize) 
{
    int seen_once = 0;
    int seen_twice = 0;

    for(int i = 0; i<numsSize; i++)
    {
        int curr_num = nums[i];

        // Bits in current number that are not already 1 in seen_twice
        int not_seen_twice = curr_num & (~seen_twice);

        seen_once ^= not_seen_twice;

        // Bits in current number that are not currently 1 in seen_once
        int seen_more_than_once = curr_num & (~seen_once);

        seen_twice ^= seen_more_than_once;
    }

    return seen_once;
    
}