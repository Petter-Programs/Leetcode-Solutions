struct NeighborInfo {
    int left;
    int up;
    int diag;
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        auto dp = std::make_unique<NeighborInfo[]>(matrix[0].size());
        NeighborInfo diagonal_curr = dp[0];
        NeighborInfo diagonal_next = dp[0];

        int best_count = 0;

        for(int i = 0; i<matrix.size(); ++i)
        {
            for(int j = 0; j<matrix[0].size(); ++j)
            {
                diagonal_curr = diagonal_next;
                diagonal_next = dp[j];

                if(matrix[i][j] != '1')
                {
                    dp[j].left = -1;
                    dp[j].up = -1;
                    dp[j].diag = -1;
                }
                else
                {
                    int left_ones = j>0 ? dp[j-1].left+1 : 0;
                    int up_ones = i>0 ? dp[j].up+1 : 0;
                    int diag_ones = i>0 && j>0 ? std::min(diagonal_curr.diag, 
                                                 std::min(diagonal_curr.left, diagonal_curr.up))+1
                                                 : 0; 

                    dp[j].left = left_ones;
                    dp[j].up = up_ones;
                    dp[j].diag = diag_ones;

                    int lcd = std::min(diag_ones, std::min(left_ones, up_ones)) + 1;

                    best_count = std::max(best_count, lcd);
                }
            }
        }

        return best_count*best_count;

    }
};