class Solution {
    int solve(vector<int>& coins, int amount,int ind,  vector<vector<int>> &dp){

        if(amount == 0){
            return 0;
        }
        if(ind ==0 ){
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        int take = 1e9;
        if(coins[ind]<= amount){
            take = 1+ solve(coins, amount-coins[ind], ind, dp);
        }
        int untake = solve(coins, amount, ind-1, dp);


        return dp[ind][amount] = min(take , untake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = solve(coins, amount, coins.size()-1, dp);
        if(ans >= 1e9){
            return -1;
        }
        return ans;
        
    }
};