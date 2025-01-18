/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #define STRING_SIZE_MAX 256
 #define STRINGS_COUNT_MAX 20

bool difference_is_one(int a, int b) {
    if (a > 0 && b < 0) {
        if (a - INT_MIN > b) {
            return false;
        }
    } else if (a < 0 && b > 0) {
        if (INT_MAX - b < a) {
            return false;
        }
    }
    
    return (a - b == 1);
}

char** summaryRanges(int* nums, int numsSize, int* returnSize) 
{
    char ** output = malloc(STRINGS_COUNT_MAX * sizeof(char*));
    
    *returnSize = 0;

    if(numsSize==0)
    {
        return output;
    }

    int lhs_idx = 0;
    int rhs_idx;

    int lhs_num = nums[lhs_idx];
    int rhs_num;

    for(rhs_idx = 1; rhs_idx<numsSize; rhs_idx++)
    {
        lhs_num = nums[lhs_idx];
        rhs_num = nums[rhs_idx];

        // printf("lhs_num is %d, rhs_num is %d\n", lhs_num, rhs_num);

        if(!difference_is_one(nums[rhs_idx], nums[rhs_idx-1]))
        {
            output[*returnSize] = malloc(STRING_SIZE_MAX * sizeof(char));
            bool type_one = (rhs_idx == lhs_idx+1);

            if(type_one)
            {
                // printf("type 1. lhs_num is %d, rhs_num is %d\n", lhs_num, rhs_num);
                sprintf(output[*returnSize], "%d", lhs_num);
            }
            else
            {
                // printf("type 2. lhs_num is %d, rhs_num is %d\n", lhs_num, nums[rhs_idx-1]);
                sprintf(output[*returnSize], "%d->%d", lhs_num, nums[rhs_idx-1]);
            }
            
            lhs_idx = rhs_idx;

            (*returnSize)++;
        }
    }

    lhs_num = nums[lhs_idx];

    if(lhs_idx < numsSize)
    {
        output[*returnSize] = malloc(STRING_SIZE_MAX * sizeof(char));
        bool type_one = (lhs_idx == numsSize-1);

        if(type_one)
        {
            sprintf(output[*returnSize], "%d", lhs_num);
        }
        else
        {
            sprintf(output[*returnSize], "%d->%d", lhs_num, nums[numsSize-1]);
        }

        (*returnSize)++;
        
    }

    return output;

}