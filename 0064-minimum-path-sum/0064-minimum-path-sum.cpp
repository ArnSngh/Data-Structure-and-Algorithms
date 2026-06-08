class Solution {

    int solve( int row, int col,vector<vector<int>>& grid) {
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        for(int r = 0; r<row; r++){
            for(int c = 0; c<col; c++){
                int left = INT_MAX;
                int up = INT_MAX;
                if(r == 0 && c == 0){
                    dp[0][0] = grid[0][0];
                    continue;
                }
                if(c>0){
                    left = grid[r][c] + dp[r][c-1];
                }
                if(r>0){
                    up = grid[r][c] + dp[r-1][c];
                }
                dp[r][c] = min(left, up);
            }
        }
        return dp[row-1][col-1];
    }



public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        return solve(row, col, grid );
        
    }
};