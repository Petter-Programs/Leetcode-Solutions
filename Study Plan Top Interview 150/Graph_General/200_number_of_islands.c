#define NEW_ISLAND '1'
#define DISCOVERED_ISLAND '2'
#define WATER '0'

void mark_territory(int i, int j, char** grid, int gridSize, int* gridColSize)
{
    if(grid[i][j] != NEW_ISLAND)
    {
        return;
    }

    grid[i][j] = DISCOVERED_ISLAND;

    if(i+1 < gridSize)
    {
        mark_territory(i+1, j, grid, gridSize, gridColSize);
    }

    if(i-1 >= 0)
    {
        mark_territory(i-1, j, grid, gridSize, gridColSize);
    }

    if(j+1 < gridColSize[0])
    {
        mark_territory(i, j+1, grid, gridSize, gridColSize);
    }

    if(j-1 >= 0)
    {
        mark_territory(i, j-1, grid, gridSize, gridColSize);
    }

}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int islands_found = 0;
    for(int i = 0; i<gridSize; i++)
    {
        for(int j = 0; j<gridColSize[0]; j++)
        {
            if(grid[i][j] == NEW_ISLAND)
            {
                mark_territory(i, j, grid, gridSize, gridColSize);
                islands_found++;
            }
        }
    }

    return islands_found;
}