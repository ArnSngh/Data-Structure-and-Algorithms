class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0]; // space = O(1)
        int maxi = 0;        // space = O(1)
        int n = prices.size();

        for(int i = 1; i < prices.size(); i++){ // time = O(n)
            if(prices[i-1] > prices[i]){
                int temp = prices[i-1] - buy;
                maxi += temp;
                buy = prices[i];
            }
        }

        maxi += prices[n-1] - buy;
        return maxi;
    }
};