class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> leftSum(n + 1), rightSum(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            int sumL = 0, sumR = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sumL += left[i];
                    sumR += right[i];
                }
            }

            leftSum[cnt].push_back(sumL);
            rightSum[cnt].push_back(sumR);
        }

        for (auto &v : rightSum) sort(v.begin(), v.end());

        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            for (int s1 : leftSum[k]) {
                int target = total / 2 - s1;
                auto &vec = rightSum[n - k];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};