class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int row_size = word1.size()+1;
        int col_size = word2.size()+1;
        auto dp = std::make_unique<int[]>(row_size * col_size);

        bool first = true;

        for(int i = 0; i<row_size; ++i)
        {
            int row_offset = i * col_size;

            for(int j = 0; j<col_size; ++j)
            {
                int left = j > 0 ? dp[row_offset + j-1] : INT_MAX;
                int up = i > 0 ? dp[(i-1) * col_size + j] : INT_MAX;
                int diag = i > 0 && j > 0 ? dp[(i-1) * col_size + j-1] : INT_MAX;

                int best = first ? 0 : std::min(std::min(left, up), diag);

                char word1_c = i > 0 ? word1[i-1] : '\0';
                char word2_c = j > 0 ? word2[j-1] : '\0';

                int cost = word1_c == word2_c && (best==diag || first) ? 0 : 1;

                dp[row_offset + j] = best+cost;

                first = false;
            }
        }

        return dp[row_size * col_size - 1];
    }
};