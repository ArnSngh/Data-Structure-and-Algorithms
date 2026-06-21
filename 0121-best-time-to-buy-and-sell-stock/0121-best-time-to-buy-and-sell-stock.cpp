class Solution {
    int solve(vector<int>& prices, int i, int mini, int profit){
        if(i == prices.size()) return profit;

        mini = min(mini, prices[i]);
        profit = max(profit, prices[i] - mini);

        return solve(prices, i + 1, mini, profit);
    }

public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, 1e9, 0);
    }
};