class Solution {
    int solve(vector<int>& prices, int i, bool flag, vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][flag] != -1) {
            return dp[i][flag];
        }

        if (flag) {
            int take = -prices[i] + solve(prices, i + 1, false, dp);
            int untake = solve(prices, i + 1, true, dp);
            return dp[i][flag] = max(take, untake);
        } else {
            int sell = prices[i] + solve(prices, i + 2, true, dp);
            int keep = solve(prices, i + 1, false, dp);
            return dp[i][flag] = max(sell, keep);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }
};