#define LETTERS_IN_ALPHABET 26


struct TrieNode
{
    std::array<int, LETTERS_IN_ALPHABET> connections_counter{};
    std::string the_word = "";
    std::array<std::unique_ptr<TrieNode>, LETTERS_IN_ALPHABET> connections{};
};

class Solution {
private:
void delete_from_trie(TrieNode *the_trie, std::string the_word)
{
    int last_idx = the_word[0] - 'a';

    TrieNode *curr = the_trie;

    for(char c : the_word)
    {
        int idx = c - 'a';

        curr->connections_counter[idx]--;

        curr = curr->connections[idx].get();
    }

    if(curr != nullptr)
    {
        curr->the_word = "";
    }
}

int coord_to_number(int num_cols, int row, int col)
{
    return row*num_cols + col;
}
void number_to_coord(int num_cols, int number, int &row, int &col)
{
    row = number/num_cols;
    col = number%num_cols;
}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
    TrieNode start_node;

    for(std::string word : words)
    {
        TrieNode *curr = &start_node;

        for(char c : word)
        {
            int idx = c - 'a';
            if(!curr->connections[idx])
            {
                curr->connections[idx] = std::make_unique<TrieNode>();
            }

            curr->connections_counter[idx]++;
            curr = curr->connections[idx].get();
        }

        curr->the_word = word;
    }

    int rows = board.size();
    int cols = board[0].size();

    std::vector<std::string> solution;

    for(int i = 0; i<rows; ++i)
    {
        for(int j = 0; j<cols; ++j)
        {
            // std::cout << "========" << std::endl;
            TrieNode *search = &start_node;
            char c = board[i][j];
            int idx = c - 'a';

            if(search->connections[idx])
            {
                int flattened_position = coord_to_number(cols, i, j);
                std::vector<int> curr_sol;
                curr_sol.push_back(flattened_position);

                std::queue<std::pair<TrieNode*, std::vector<int>>> bfs;

                bfs.push(std::make_pair(search->connections[idx].get(), curr_sol));

                while(bfs.size()>0)
                {
                    TrieNode *curr_search = bfs.front().first;


                    std::vector<int> existing_sol = bfs.front().second;

                    int position_flat = existing_sol.back();

                    int r, c;
                    number_to_coord(cols, position_flat, r, c);

                    bfs.pop();

                    if(curr_search->the_word != "")
                    {
                        solution.push_back(curr_search->the_word);
                        delete_from_trie(&start_node, curr_search->the_word);
                    }

                    if(r > 0)
                    {
                        char letter = board[r-1][c];
                        char letter_idx = letter - 'a';
                        int next_flattened = coord_to_number(cols, r-1, c);
                        if(curr_search->connections[letter_idx] 
                        && curr_search->connections_counter[letter_idx] > 0
                        && std::find(existing_sol.begin(), existing_sol.end(), next_flattened) == existing_sol.end())
                        {
                            existing_sol.push_back(next_flattened);
                            bfs.push(std::make_pair(curr_search->connections[letter_idx].get(), existing_sol));
                            existing_sol.pop_back();
                        }
                    }

                    if(r < rows-1)
                    {
                        char letter = board[r+1][c];
                        char letter_idx = letter - 'a';
                        int next_flattened = coord_to_number(cols, r+1, c);
                        if(curr_search->connections[letter_idx] 
                        && curr_search->connections_counter[letter_idx] > 0
                        && std::find(existing_sol.begin(), existing_sol.end(), next_flattened) == existing_sol.end())
                        {
                            existing_sol.push_back(next_flattened);
                            bfs.push(std::make_pair(curr_search->connections[letter_idx].get(), existing_sol));
                            existing_sol.pop_back();
                        }
                    }

                    if(c > 0)
                    {
                        char letter = board[r][c-1];
                        char letter_idx = letter - 'a';
                        int next_flattened = coord_to_number(cols, r, c-1);
                        if(curr_search->connections[letter_idx] 
                        && curr_search->connections_counter[letter_idx] > 0
                        && std::find(existing_sol.begin(), existing_sol.end(), next_flattened) == existing_sol.end())
                        {
                            existing_sol.push_back(next_flattened);
                            bfs.push(std::make_pair(curr_search->connections[letter_idx].get(), existing_sol));
                            existing_sol.pop_back();
                        }
                    }

                    if(c < cols-1)
                    {
                        char letter = board[r][c+1];
                        char letter_idx = letter - 'a';
                        int next_flattened = coord_to_number(cols, r, c+1);
                        if(curr_search->connections[letter_idx] 
                        && curr_search->connections_counter[letter_idx] > 0
                        && std::find(existing_sol.begin(), existing_sol.end(), next_flattened) == existing_sol.end())
                        {
                            existing_sol.push_back(next_flattened);
                            bfs.push(std::make_pair(curr_search->connections[letter_idx].get(), existing_sol));
                            existing_sol.pop_back();
                        }
                    }
                }                
            }

            
        }
    }

    return solution;

        
}
};