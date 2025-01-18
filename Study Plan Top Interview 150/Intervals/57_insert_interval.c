bool is_after(int* range1, int*range2)
{
    return range1[0] > range2[1];
}

bool intersects(int *range1, int* range2)
{
    // let's assume range1 starts before range2
    // and swap if not the case

    if(range2[0] < range1[0])
    {
        int *temp = range2;
        range2 = range1;
        range1 = temp;
    }

    return range1[1]>=range2[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{

    // Just go through reconstructing the array
    // Keep track of interval inserting
    // The only time we care about modifying anything is once we intersect
    // Then after we are done, we might care about finding ranges that are inside the new max
    // Also, we might not intersect at all; so we need to check if we'd have fit before

    // at most same size as old one plus one interval
    int ** new_intervals = malloc(sizeof(int*) * (intervalsSize+1));
    (*returnColumnSizes) = malloc(sizeof(int) * (intervalsSize+1));

    for(int i = 0; i<(intervalsSize+1); i++)
    {
        new_intervals[i] = malloc(sizeof(int)*2);
        (*returnColumnSizes)[i] = 2;
    }

    bool inserted = false;
    bool inserting = false;

    int new_idx = 0;

    int new_max = INT_MIN;

    int newSize = 0;

    for(int i = 0; i<intervalsSize; i++)
    {
        if(inserted)
        {
            new_intervals[new_idx][0] = intervals[i][0];
            new_intervals[new_idx][1] = intervals[i][1];
            newSize++;
            new_idx++;
            continue;
        }

        if(inserting)
        {
            if(intervals[i][0] > new_max)
            {
                new_idx++;
                new_intervals[new_idx][0] = intervals[i][0];
                new_intervals[new_idx][1] = intervals[i][1];
                new_idx++;
                newSize++;
                inserted = true;
                continue;
            }

            else if(intervals[i][1] > new_max)
            {
                new_max = intervals[i][1];
                new_intervals[new_idx][1] = new_max;
                continue;
            }

            continue;

        }

        if(is_after(intervals[i], newInterval))
        {
            new_intervals[new_idx][0] = newInterval[0];
            new_intervals[new_idx][1] = newInterval[1];
            new_idx++;
            new_intervals[new_idx][0] = intervals[i][0];
            new_intervals[new_idx][1] = intervals[i][1];
            inserted = true;
            new_idx++;
            newSize+=2;
            continue;
        }

        if(intersects(newInterval, intervals[i]))
        {
            if(newInterval[0] > intervals[i][0])
                new_intervals[new_idx][0] = intervals[i][0];
            else
                new_intervals[new_idx][0] = newInterval[0];

            if(newInterval[1]>intervals[i][1])
            {
                new_intervals[new_idx][1] = newInterval[1];
                new_max = newInterval[1];
                inserting = true;
                newSize++;
                continue;
            }

            else
            {
                new_intervals[new_idx][1] = intervals[i][1];
                new_idx++;
                newSize++;
                inserted = true;
                continue;
            }
        }

        // Fallback case; 
        new_intervals[new_idx][0] = intervals[i][0];
        new_intervals[new_idx][1] = intervals[i][1];
        new_idx++;
        newSize++;
    }

    if(!inserted && new_max == INT_MIN)
    {
        new_intervals[new_idx][0] = newInterval[0];
        new_intervals[new_idx][1] = newInterval[1];
        newSize++;
    }

    *returnSize = newSize;

    return new_intervals;
}