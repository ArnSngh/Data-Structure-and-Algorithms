#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<vector<int>> res;
        
        auto backtrack = [&](auto&& self, vector<int> &curr) -> void {
            if (curr.size() == n) {
                res.push_back(curr);
                return;
            }

            for (int i=0; i<n; i++) {
                if (used[i]) {
                    continue;
                }
                
                used[i] = true;
                curr.push_back(nums[i]);
                self(self, curr);
                curr.pop_back();
                used[i] = false;
            }
            return;
        };
        
        vector<int> curr;
        backtrack(backtrack, curr);
        return res;

    }
};