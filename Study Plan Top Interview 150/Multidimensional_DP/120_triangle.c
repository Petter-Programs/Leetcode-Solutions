static int min(int a, int b) {
    if(a<=b)
        return a;
    
    return b;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) 
{
    int **min_triangle = malloc(sizeof(int*) * triangleSize);
    
    for(int i = 0; i<triangleSize; i++)
    {
        min_triangle[i] = malloc(sizeof(int) * triangleColSize[i]);

        for(int j = 0; j<triangleColSize[i]; j++)
        {
            min_triangle[i][j] = INT_MAX;
        }
    }

    for(int j = 0; j<triangleColSize[triangleSize-1]; j++)
    {
        min_triangle[triangleSize-1][j] = triangle[triangleSize-1][j];
    }

    for(int row = triangleSize-2; row>=0; row--)
    {
        for(int col = 0; col<triangleColSize[row]; col++)
        {
            int down_straight_col = min_triangle[row+1][col];
            int down_right_col = min_triangle[row+1][col+1];
            min_triangle[row][col] = min(min_triangle[row][col], triangle[row][col] + min(down_straight_col, down_right_col));
        }
    }

    return min_triangle[0][0];
    
}