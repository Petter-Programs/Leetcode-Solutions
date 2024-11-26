void increment_counter(int cell, int *alive_counter)
{    
    if(cell == 1 || cell == 2)
        (*alive_counter)++;
}

void gameOfLife(int** board, int boardSize, int* boardColSize)
{

for(int round = 0; round<2; round++)
{
    for(int i = 0; i<boardSize; i++)
    {
        for(int j = 0; j<(*boardColSize); j++)
        {
            if(round == 0)
            {
                int alive_neighbors = 0;

                bool up_exists = i>0;
                bool down_exists = i<boardSize-1;
                bool left_exists = j>0;
                bool right_exists = j<(*boardColSize)-1;

                int left_neighbor = left_exists ? board[i][j-1] : -1;
                int left_up_neighbor = left_exists && up_exists ? board[i-1][j-1] : -1;
                int left_down_neighbor = left_exists && down_exists ? board[i+1][j-1] : -1;
                int up_neighbor = up_exists ? board[i-1][j] : -1;
                int down_neighbor = down_exists ? board[i+1][j] : -1;
                int right_neighbor = right_exists ? board[i][j+1] : -1;
                int right_up_neighbor = right_exists && up_exists ? board[i-1][j+1] : -1;
                int right_down_neighbor = right_exists && down_exists ? board[i+1][j+1] : -1;

                increment_counter(left_neighbor, &alive_neighbors);
                increment_counter(left_up_neighbor, &alive_neighbors);
                increment_counter(left_down_neighbor, &alive_neighbors);
                increment_counter(up_neighbor, &alive_neighbors);
                increment_counter(down_neighbor, &alive_neighbors);
                increment_counter(right_neighbor, &alive_neighbors);
                increment_counter(right_up_neighbor, &alive_neighbors);
                increment_counter(right_down_neighbor, &alive_neighbors);

                if(board[i][j] == 1)
                {
                    if(alive_neighbors < 2)
                        board[i][j] = 2;

                    if(alive_neighbors > 3)
                        board[i][j] = 2;

                }
                else
                {
                    printf("Was dead, my alive neighbors is %d\n", alive_neighbors);
                    if(alive_neighbors == 3)
                        board[i][j] = 3;
                }
            }
            else
            {
                if(board[i][j] == 2)
                    board[i][j] = 0;

                if(board[i][j] == 3)
                    board[i][j] = 1;
            }

        }
    }
}

// not applicable -1
// dead 0
// alive 1
// dead was alive 2
// alive was dead 3

// but this requires another loop to update to correct

}