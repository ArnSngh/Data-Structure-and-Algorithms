class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for(int ind = 0; ind<coins.size(); ind++){
            for(int target = 0; target<= amount; target++){
                if(ind == 0){
                    if(target%coins[0] == 0){
                      dp[ind][target] = target/coins[0];
                    }
                    else{
                     dp[ind][target] = 1e9;
                 }
                 continue;
                }

                int take = 1e9;
                if(coins[ind] <= target){
                    take = 1 + dp[ind][target-coins[ind]];
                }
                int notake = dp[ind-1][target];
                dp[ind][target] = min(take, notake);
            }
        }

        if(dp[coins.size()-1][amount]>= 1e9){
            return -1;
        }
        else return dp[coins.size()-1][amount];
        
    }
};