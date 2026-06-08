class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {

                // obstacle
                if(obstacleGrid[r][c] == 1) {
                    dp[r][c] = 0;
                    continue;
                }

                // source
                if(r == 0 && c == 0) {
                    dp[r][c] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if(r > 0)
                    up = dp[r - 1][c];

                if(c > 0)
                    left = dp[r][c - 1];

                dp[r][c] = up + left;
            }
        }

        return dp[row - 1][col - 1];
    }
};