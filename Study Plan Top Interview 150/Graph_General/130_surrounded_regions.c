#define DEAD_SQUARE 'X'
#define DANGER_SQUARE 'O'
#define SAFE_SQUARE 'P'

void mark_square(int i, int j, char **board, int boardSize, int colSize)
{
    board[i][j] = SAFE_SQUARE;

    if(i > 0 && board[i-1][j] == DANGER_SQUARE)
    {
        mark_square(i-1, j, board, boardSize, colSize);
    }

    if(i < boardSize-1 && board[i+1][j] == DANGER_SQUARE)
    {
        mark_square(i+1, j, board, boardSize, colSize);
    }

    if(j > 0 && board[i][j-1] == DANGER_SQUARE)
    {
        mark_square(i, j-1, board, boardSize, colSize);
    }

    if(j < colSize-1 && board[i][j+1] == DANGER_SQUARE)
    {
        mark_square(i, j+1, board, boardSize, colSize);
    }

}

void solve(char** board, int boardSize, int* boardColSize) 
{
    // each region with an 'O' that does not have some 'O' on the corners should be replaced
    // we could go through just the sides, and mark the safe regions with like 'P'
    // then we'd go through the board and replace all remaining 'O's with 'X's
    // then replace the 'P's back with 'O's

    int colSize = boardColSize[0];

    for(int i = 0; i<boardSize; i++)
    {
        for(int j = 0; j<colSize; j++)
        {
            if(i != 0 && i != boardSize-1 && j != 0 && j!= colSize-1)
            {
                continue;
            }

            if(board[i][j] == DANGER_SQUARE)
            {
                mark_square(i, j, board, boardSize, colSize);
            }
            
        }
    }

    for(int i = 0; i<boardSize; i++)
    {
        for(int j = 0; j<colSize; j++)
        {
            if(board[i][j] == DANGER_SQUARE)
            {
                board[i][j] = DEAD_SQUARE;
            }
            else if(board[i][j] == SAFE_SQUARE)
            {
                board[i][j] = DANGER_SQUARE;
            }
        }
    }
    
}