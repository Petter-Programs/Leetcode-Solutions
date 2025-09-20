#define LD(row, col) (row+col)
#define RD(row, col, board_size) ((row-col)+board_size)

class Solution {
private:
    void dfs(std::vector<bool>& occupied_ld, std::vector<bool>& occupied_rd, std::vector<bool>& occupied_col, int max_rows, int curr_row, int& pos_identified)
    {
        for(int col = 0; col<max_rows; ++col)
        {
            int ld = LD(curr_row, col);
            int rd = RD(curr_row, col, max_rows);

            if(!occupied_col[col] 
            && !occupied_ld[ld] 
            && !occupied_rd[rd])   
            {
                if(curr_row == max_rows-1)
                {
                    pos_identified++;
                }

                else
                {
                    occupied_col[col] = true;
                    occupied_rd[rd] = true;
                    occupied_ld[ld] = true;
                    dfs(occupied_ld, occupied_rd, occupied_col, max_rows, curr_row+1, pos_identified);
                    occupied_col[col] = false;
                    occupied_rd[rd] = false;
                    occupied_ld[ld] = false;
                }
            }
        }
    }
public:
    int totalNQueens(int n) 
    {
        std::vector<bool> occupied_ld(n, false);
        std::vector<bool> occupied_rd(n, false);
        std::vector<bool> occupied_col(n, false);

        int queens = 0;

        dfs(occupied_ld, occupied_rd, occupied_col, n, 0, queens);

        return queens;
        
    }
};