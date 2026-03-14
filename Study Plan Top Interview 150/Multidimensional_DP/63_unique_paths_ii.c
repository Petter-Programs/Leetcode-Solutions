#define OBSTACLE 1

static bool is_blocked(int * const * obstacleGrid, int row, int col, int row_size, int col_size)
{
    if(row >= row_size || col >= col_size)
    {
        return true;
    }

    return obstacleGrid[row][col] == OBSTACLE;
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    
    if(obstacleGrid[0][0] == OBSTACLE)
        return 0;

    int **count_grid = malloc(sizeof(int*) * obstacleGridSize);

    for(int i = 0; i<obstacleGridSize; i++)
    {
        count_grid[i] = calloc(obstacleGridColSize[0], sizeof(int));
    }

    count_grid[0][0] = 1;

    for(int i = 0; i<obstacleGridSize; i++)
    {
        for(int j = 0; j<obstacleGridColSize[0]; j++)
        {
            if(obstacleGrid[i][j] == OBSTACLE)
                continue;

            bool down_unblocked = !is_blocked(obstacleGrid, i+1, j,
                                           obstacleGridSize, obstacleGridColSize[0]);

            bool right_unblocked = !is_blocked(obstacleGrid, i, j+1, 
                                              obstacleGridSize, obstacleGridColSize[0]);

            if(down_unblocked)
            {
                count_grid[i+1][j] += count_grid[i][j];
            }

            if(right_unblocked)
            {
                count_grid[i][j+1] += count_grid[i][j];
            }
        }
    }

    return count_grid[obstacleGridSize-1][obstacleGridColSize[0]-1];

}