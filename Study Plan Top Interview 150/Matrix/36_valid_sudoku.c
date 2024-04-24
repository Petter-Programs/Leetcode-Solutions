struct NumberStruct
{
int row;
int column;
int square;
int can_overwrite;
};

bool isValidSudoku(char** board, int boardSize, int* boardColSize) 
{
    struct NumberStruct *numbers[10];

    for(int i = 0; i<10; i++)
    {
        numbers[i] = malloc(sizeof(struct NumberStruct) * 10);
        numbers[i][0].can_overwrite = 1;
     }

     for(int row = 0; row<9; row++)
     {
        for(int col = 0; col<9; col++)
        {
            char current = board[row][col];

            if(current!='.')
            {
                int current_int = current - '0';
                int current_square = (row/3 * 3) + col/3;

                struct NumberStruct *num = numbers[current_int];

                int number_inside = 0;
                struct NumberStruct active_num = num[number_inside];

                while(active_num.can_overwrite!=1)
                {
                    if(active_num.row == row
                    || active_num.column == col
                    || active_num.square == current_square)
                        return 0;

                    number_inside++;
                    active_num = num[number_inside];
                }

                struct NumberStruct current_number;
                current_number.row = row;
                current_number.column = col;
                current_number.square = current_square;
                current_number.can_overwrite = 0;

                num[number_inside] = current_number;

                num[number_inside+1].can_overwrite = 1;
                
            }

        }
     }

    for(int i = 0; i<10; i++)
    {
        free(numbers[i]);
    }

    return 1;

}