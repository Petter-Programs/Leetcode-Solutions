#define NORMAL_SQUARE -1

#define VISITING 1
#define VISITED 2

class Solution 
{

private:

void index_to_position(int& the_index, int board_size, int& row, int& column)
{
    if(the_index >= board_size*board_size)
    {
        int last_row_from_bottom = ((board_size*board_size)-1) / board_size;
        bool last_row_left_to_right = last_row_from_bottom % 2 == 0;
        
        row = 0;
        column = last_row_left_to_right ? board_size-1 : 0;

        the_index = board_size*board_size;

        return;
    }

    int row_from_bottom = (the_index-1) / board_size;

    bool left_to_right = row_from_bottom % 2 == 0;

    int squares_before_row = row_from_bottom*board_size;
    int idx_from_beginning = the_index - squares_before_row - 1;

    if(left_to_right)
    {
        column = idx_from_beginning;
    }
    else
    {
        column = board_size-1 - idx_from_beginning;
    }

    row = board_size-1 - row_from_bottom;
}

public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int const dice_size = 6;
        
        bool left_to_right = true;

        int const square_count = board.size()*board.size();

        vector<int> visited_record(square_count+1); // 1-based so not using the first square
        
        std::queue<std::pair<int, int>> to_visit;

        // square 1, 0 rolls of the dice
        to_visit.push(std::make_pair(1, 0));

        int row, col;

        while(to_visit.size() > 0)
        {
            int curr = to_visit.front().first;
            int moves = to_visit.front().second;
            to_visit.pop();

            if(visited_record[curr] == VISITED)
                continue;

            visited_record[curr] = VISITED;

            // Fill row and col with correct positions for current
            index_to_position(curr, board.size(), row, col);
            
            for(int i = dice_size; i > 0; --i)
            {
                // consider the case where we're past the goal
                // helper function takes care of this, it will just return the last square

                int next_index = curr+i;

                index_to_position(next_index, board.size(), row, col);

                bool normal_square = board[row][col] == NORMAL_SQUARE;

                int real_next_idx = normal_square ? next_index : board[row][col]; 

                // We know this won't be a special square, from the definition
                // It's been adjusted to point at most to square_count, from index_to_position
                if(real_next_idx == square_count)
                {
                    return moves+1;
                }

                if(visited_record[real_next_idx] == VISITED || visited_record[real_next_idx] == VISITING)
                {
                    continue;
                }

                visited_record[real_next_idx] = VISITING;

                int next_row, next_col;
                int index_after = real_next_idx+1;
                index_to_position(index_after, board.size(), next_row, next_col);

                // We're a normal square and ahead of us is a visited normal square;
                // this normal square must cover all the area that we can cover, so we can just dismiss here
                if(normal_square && board[next_row][next_col] == NORMAL_SQUARE && (visited_record[index_after] == VISITED || visited_record[index_after] == VISITING))
                {
                    continue;
                }

                to_visit.push(std::make_pair(real_next_idx, moves+1));
            }


        }

        return -1;

        
    }
};