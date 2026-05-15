class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int Lsum = 0;
        int Rsum = 0;
        int n = cardPoints.size();
        int total = 0;

        // Take first k cards from left
        for(int i = 0; i < k; i++) {
            Lsum += cardPoints[i];
        }

        total = Lsum;

        // Replace left cards with right cards one by one
        for(int i = k - 1; i >= 0; i--) {
            Lsum -= cardPoints[i];
            Rsum += cardPoints[n - 1];
            n--;

            total = max(total, Lsum + Rsum);
        }

        return total;
    }
};