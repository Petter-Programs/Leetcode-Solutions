static int min(int a, int b)
{
    return a <= b ? a : b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) 
{
    int *row_above = malloc(sizeof(int) * gridColSize[0]);

    for(int i = 0; i<gridColSize[0]; i++)
    {
        row_above[i] = INT_MAX;
    }

    row_above[0] = 0;

    int lhs_entry = INT_MAX;

    for(int i = 0; i<gridSize; i++)
    {
        for(int j = 0; j<gridColSize[0]; j++)
        {
            int up_entry = row_above[j];

            row_above[j] = grid[i][j] + min(up_entry, lhs_entry);

            lhs_entry = row_above[j];
        }
    }

    return row_above[gridColSize[0]-1];   
}