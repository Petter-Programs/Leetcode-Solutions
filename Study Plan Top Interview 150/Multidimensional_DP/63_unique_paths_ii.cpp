#define OBSTRUCTED 1

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        // holds counts both for left and above
        vector<int> dp(obstacleGrid[0].size(), 0);

        dp[0] = 1;

        for(int i = 0; i<obstacleGrid.size(); i++)
        {
            for(int j = 0; j<obstacleGrid[0].size(); j++)
            {
                if(obstacleGrid[i][j] == OBSTRUCTED)
                {
                    dp[j] = 0;
                    continue;
                }

                int left = j>0 ? dp[j-1] : 0;
                int above = dp[j];

                dp[j] = above + left;
            }
        }

        return dp[obstacleGrid[0].size()-1];
        
    }
};