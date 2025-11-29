// Quick select approach with duplicates handling

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *nums, int start_idx, int end_idx)
{
    int pivot = nums[end_idx-1];

    int i = start_idx;
    // don't want to touch the pivot
    for(int j = start_idx; j<end_idx-1; j++)
    {
        if(nums[j] < pivot)
        {
            swap(&nums[j], &nums[i]);
            i++;
        }
    }

    swap(&nums[end_idx-1], &nums[i]);

    return i;
}

int quick_select(int *nums, int k, int start_idx, int end_idx)
{
    int range_size = end_idx-start_idx;

    if(range_size <= 1)
        return nums[start_idx];

    int rand_idx = (rand() % range_size) + start_idx;

    swap(&nums[end_idx-1], &nums[rand_idx]);

    int maybe_k = partition(nums, start_idx, end_idx);
    int maybe_k_val = nums[maybe_k];

    int right_pivot = maybe_k + 1;

    for (int j = maybe_k + 1; j < end_idx; ++j) 
    {
        if (nums[j] == maybe_k_val) 
        {
            swap(&nums[j], &nums[right_pivot]);
            right_pivot++;
        }
    }

    int target = k - 1;

    if (target < maybe_k) 
    {
        return quick_select(nums, k, start_idx, maybe_k);
    } 
    
    else if (target < right_pivot) 
    {
        return maybe_k_val;
    } 

    else 
    {
        return quick_select(nums, k, right_pivot, end_idx);
    }

}

int findKthLargest(int* nums, int numsSize, int k) 
{
    srand(time(NULL));

    return quick_select(nums, numsSize-(k-1), 0, numsSize);
}