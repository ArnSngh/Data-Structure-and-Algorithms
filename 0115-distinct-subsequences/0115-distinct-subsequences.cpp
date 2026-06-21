class Solution {
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp) {
        if (j < 0) return 1;   // t fully matched
        if (i < 0) return 0;   // s finished but t left
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            int pick = solve(s, t, i - 1, j - 1,dp);
            int notPick = solve(s, t, i - 1, j,dp);
            return dp[i][j] = pick + notPick;
        }

        return dp[i][j] = solve(s, t, i - 1, j,dp);
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(s, t, s.size() - 1, t.size() - 1,dp);
    }
};