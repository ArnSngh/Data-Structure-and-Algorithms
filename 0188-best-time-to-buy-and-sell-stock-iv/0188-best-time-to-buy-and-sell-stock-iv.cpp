class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(k+1, vector<int>(2, 0))
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = k; buy >= 0; buy--) {
                for (int flag = 1; flag >= 0; flag--) {

                    if (buy == 0) {
                        dp[i][buy][flag] = 0;
                        continue;
                    }

                    if (flag == 1) {
                        dp[i][buy][flag] =
                            max(-prices[i] + dp[i + 1][buy][0],
                                dp[i + 1][buy][1]);
                    } 
                    else {
                        dp[i][buy][flag] =
                            max(prices[i] + dp[i + 1][buy - 1][1],
                                dp[i + 1][buy][0]);
                    }
                }
            }
        }

        return dp[0][k][1];
    }
};