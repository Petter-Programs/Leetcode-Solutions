int get_steps_to_jump(int row, int *col, int numRows)
{
    int col_span = numRows - 1;

    if(row == 0 || row == numRows-1)
    {
        (*col)+=col_span;
        return (numRows-1)*2;
    }

    // going down, then up
    if((*col) % col_span == 0)
    {
        int distance_down = numRows-(row+1); // down, same column
        int distance_up = distance_down; // switch col at every step

        (*col)+=(distance_up);
        return distance_down+distance_up;
    }

    int distance_up = row;
    int distance_down = row;

    (*col)+=(distance_up);
    return distance_up+distance_down;
}

char* convert(char* s, int numRows) 
{
    if(numRows == 1)
    {
        return s;
    }

    int string_len =  strlen(s);
    char *return_string = malloc(sizeof(char) * string_len+1);

    int row = 0;
    int column = 0;
    int str_idx = 0;

    while(row < numRows)
    {
        char *string_ptr = s+row;
        int curr_idx = 0;

        while(curr_idx < string_len-row)
        {
            return_string[str_idx++] = *string_ptr;

            int steps_to_jump = get_steps_to_jump(row, &column, numRows);
            string_ptr+=steps_to_jump;
            curr_idx+=steps_to_jump;
        }

        row++;
        column = 0;

    }

    return_string[str_idx] = '\0';
    return return_string;

}