class Solution {

    int solve(int row, int col,vector<vector<int>>& triangle, vector<vector<int>>& dp ){
        if(row == 0 && col == 0){
            return triangle[0][0];
        }
        if(row<0|| col<0 || col>row){
            return 1e9;
        }
        if(dp[row][col] !=-1){
            return dp[row][col];
        }
        int a = INT_MAX;
        int b = INT_MAX;
        if(row>0){
            a =triangle[row][col]+ solve(row-1, col, triangle, dp);
        }
        if(col>0){
            b = triangle[row][col]+ solve(row-1, col-1, triangle, dp);
        }
        return dp[row][col] = min(a,b);

        
    }



public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        int ans = 1e9;

        for(int col = 0; col < triangle[row - 1].size(); col++) {
            ans = min(ans, solve(row - 1, col, triangle, dp));
        }

        return ans;

        
    }
};