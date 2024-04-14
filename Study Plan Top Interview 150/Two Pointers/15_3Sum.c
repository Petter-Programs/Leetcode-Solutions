// Heavily drawn from solution by:
// https://leetcode.com/problems/3sum/solutions/3223429/pure-c-solution

int compare(const void* a, const void* b)
{
    int* a_int = (int*) a;
    int* b_int = (int*) b;

    return *a_int - *b_int;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    int **return_arrays = malloc(sizeof(int*) * numsSize * numsSize);
    (*returnColumnSizes) =  malloc(sizeof(int) * numsSize * numsSize);
    (*returnSize) = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0; i<numsSize-2; i++)
    {
        if(i==0 || nums[i-1] != nums[i])
        {
            int left = i+1;
            int right = numsSize-1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum > 0)
                    right--;

                else if(sum < 0)
                    left++;

                else
                {
                    return_arrays[(*returnSize)] = malloc(sizeof(int) * 3);

                    return_arrays[(*returnSize)][0] = nums[i];
                    return_arrays[(*returnSize)][1] = nums[left];
                    return_arrays[(*returnSize)][2] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 3;

                    (*returnSize)++;

                    do
                        left++;
                    while (left < right && nums[left] == nums[left-1]);
                }

            }

        }

    }

    return return_arrays;
}