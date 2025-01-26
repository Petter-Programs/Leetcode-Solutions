int compare(const void* first, const void* second)
{
    int **first_actual = (int**) first;
    int **second_actual = (int**) second;

    return (first_actual[0][0] > second_actual[0][0]);
}

bool overlaps(int *first_interval, int *second_interval)
{
    if(first_interval[0]>second_interval[0])
    {
        int *tmp = first_interval;
        second_interval = first_interval;
        first_interval = tmp;
    }

    return first_interval[1]>=second_interval[0];
}

int max(int first, int second)
{
    if(first>=second)
    {
        return first;
    }
    return second;
}

int min(int first, int second)
{
    if(first<=second)
    {
        return first;
    }
    return second;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) 
{
    qsort(points, pointsSize, sizeof(int*), compare);

    int count = 0;

    if(pointsSize<=0)
    {
        return count;
    }

    count++;

    for(int i = 1; i<pointsSize; i++)
    {
        if(overlaps(points[i-1], points[i]))
        {
            points[i][0] = max(points[i-1][0], points[i][0]);
            points[i][1] = min(points[i-1][1], points[i][1]);
        }
        else
        {
            count++;
        }
    }

    return count;

}