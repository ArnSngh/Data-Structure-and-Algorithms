class Solution {
    int solve(vector<int>& arr, int target, int ind, vector<vector<int>>& dp) {
        if(ind == 0){
        if(target == 0 && arr[0] == 0) return 2;
         if(target == 0 || target == arr[0]) return 1;
          return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = solve(arr, target, ind - 1, dp);

        int take = 0;
        if (arr[ind] <= target) {
            take = solve(arr, target - arr[ind], ind - 1, dp);
        }

        return dp[ind][target] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i =0 ; i<n; i++){
            sum += nums[i];
        }

        if(sum - target < 0 || (sum - target)%2 != 0) return 0;

        int k = (sum - target)/2;

        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        return solve(nums,k,n-1, dp);
        
    }
};