class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int start = n - 1; start >= 0; start--) {
            for (int end = start; end < n; end++) {

                if (start == end) {
                    dp[start][end] = 1;
                }
                else if (s[start] == s[end]) {
                    dp[start][end] = 2 + dp[start + 1][end - 1];
                }
                else {
                    int skip1 = dp[start + 1][end];
                    int skip2 = dp[start][end - 1];
                    dp[start][end] = max(skip1, skip2);
                }
            }
        }

        return dp[0][n - 1];
    }
};