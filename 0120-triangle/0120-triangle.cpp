class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0][0] = triangle[0][0];

        for(int r = 1; r < n; r++) {
            for(int c = 0; c <= r; c++) {

                int up = 1e9;
                int diagonal = 1e9;

                if(c < r)
                    up = triangle[r][c] + dp[r-1][c];

                if(c > 0)
                    diagonal = triangle[r][c] + dp[r-1][c-1];

                dp[r][c] = min(up, diagonal);
            }
        }

        int ans = 1e9;

        for(int c = 0; c < n; c++) {
            ans = min(ans, dp[n-1][c]);
        }

        return ans;
    }
};