class Solution {
private:
    bool dfs(std::string& curr_word, std::string& target_word, vector<vector<char>>& board, std::vector<std::vector<bool>>& already_visited, int i, int j)
    {
        already_visited[i][j] = true;

        if(curr_word == target_word)
        {
            return true;
        }
        if(curr_word.length() < target_word.length())
        {
            if(i > 0 && !already_visited[i-1][j])
            {
                int next_char = board[i-1][j];

                if(target_word[curr_word.length()] == next_char)
                {
                    curr_word += next_char;
                    if(dfs(curr_word, target_word, board, already_visited, i-1, j))
                    {
                        return true;
                    }
                    curr_word.pop_back();
                }
            }

            if(i < board.size()-1 && !already_visited[i+1][j])
            {
                int next_char = board[i+1][j];
                if(target_word[curr_word.length()] == next_char)
                {
                    curr_word += next_char;
                    if(dfs(curr_word, target_word, board, already_visited, i+1, j))
                    {
                        return true;
                    }
                    curr_word.pop_back();
                }
            }

            if(j > 0 && !already_visited[i][j-1])
            {
                int next_char = board[i][j-1];
                if(target_word[curr_word.length()] == next_char)
                {
                    curr_word += next_char;
                    if(dfs(curr_word, target_word, board, already_visited, i, j-1))
                    {
                        return true;
                    }
                    curr_word.pop_back();
                }
            }

            if(j < board[0].size()-1 && !already_visited[i][j+1])
            {
                int next_char = board[i][j+1];
                if(target_word[curr_word.length()] == next_char)
                {
                    curr_word += next_char;
                    if(dfs(curr_word, target_word, board, already_visited, i, j+1))
                    {
                        return true;
                    }
                    curr_word.pop_back();
                }
            }
        }

        already_visited[i][j] = false;
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int board_rows = board.size();
        int board_cols = board[0].size();

        std::vector<std::vector<bool>> already_visited(board_rows, std::vector<bool>(board_cols, false));

        for(int i = 0; i<board_rows; ++i)
        {
            for(int j = 0; j<board_cols; ++j)
            {
                std::string curr_word(1, board[i][j]);
                if(dfs(curr_word, word, board, already_visited, i, j))
                {
                    return true;
                }
            }
        }

        return false;


    }
};
