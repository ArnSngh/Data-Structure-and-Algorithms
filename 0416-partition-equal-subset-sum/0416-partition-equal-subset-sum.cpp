class Solution {
    bool solve(vector<int> &nums, int target) {

        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int index = n - 1; index >= 0; index--) {

            for (int t = 1; t <= target; t++) {

                bool pick = false;

                if (nums[index] <= t) {
                    pick = dp[index + 1][t - nums[index]];
                }

                bool unpick = dp[index + 1][t];

                dp[index][t] = pick || unpick;
            }
        }

        return dp[0][target];
    }

public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (sum % 2 != 0) {
            return false;
        }

        return solve(nums, sum / 2);
    }
};