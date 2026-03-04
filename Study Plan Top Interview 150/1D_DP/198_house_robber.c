static int max(int a, int b)
{
    if(a >= b)
        return a;
    return b;
}

int rob(int* nums, int numsSize) 
{
    int max_at_idx_minus_1 = 0;
    int max_at_idx_minus_2 = 0;
    
    for(int i = 0; i < numsSize; i++) {
        int tmp = max(max_at_idx_minus_1, max_at_idx_minus_2 + nums[i]);
        max_at_idx_minus_2 = max_at_idx_minus_1;
        max_at_idx_minus_1 = tmp;
    }

    return max_at_idx_minus_1;
    
}