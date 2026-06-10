class Solution {
    int solve(vector<int> &nums, int target, int index, vector<vector<int>> & dp){
         if(target == 0){
            return true;
        }
        if(index == nums.size()){
            return false;
        }
        if(dp[index][target] != -1){
            return dp[index][target]; // it will never return -1 , only return 0 and 1
        }
       
        bool pick = false;
        if(nums[index] <= target){
            pick = solve(nums, target - nums[index], index +1, dp);
        }
        bool unpick = solve(nums, target, index +1, dp);

        return dp[index][target] =  pick || unpick;

    }
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum = sum + nums[i];
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));
        if(sum%2 != 0){
            return false;
        }
        return solve(nums, sum/2, 0, dp);
        
    }
};