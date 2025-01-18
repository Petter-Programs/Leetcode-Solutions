int compare(const void *a, const void* b)
{
    int ** a_actual = (int**)a;
    int ** b_actual = (int**)b;

    return a_actual[0][0] - b_actual[0][0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int replace_idx = 0;

    int last_max = intervals[0][1];

    for(int i = 1; i<intervalsSize; i++)
    {   
        int curr_min = intervals[i][0];
        int curr_max = intervals[i][1];

        if(curr_min <= last_max)
        {
            if(curr_max > last_max)
            {
                intervals[replace_idx][1] = curr_max;
                last_max = curr_max;
            }
        }
        else
        {
            replace_idx++;
            intervals[replace_idx][0] = curr_min;
            intervals[replace_idx][1] = curr_max;
            last_max = curr_max;
        }
    }

    *returnSize = replace_idx+1;
    
    int ** return_arr = malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));

    for(int i = 0; i<*returnSize; i++)
    {
       return_arr[i] = malloc(sizeof(int) * 2);

       return_arr[i][0] = intervals[i][0];
       return_arr[i][1] = intervals[i][1];

       (*returnColumnSizes)[i] = 2;
    }

    return return_arr;

}