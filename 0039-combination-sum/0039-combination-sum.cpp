class Solution {

    void fxn(int index, int target,
             vector<int>& nums,
             int sum,
             vector<vector<int>>& ans,
             vector<int>& temp) {

        // base case
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        if (index == nums.size() || sum > target) {
            return;
        }

        // pick and stay on same index
        temp.push_back(nums[index]);
        fxn(index, target, nums,
            sum + nums[index],
            ans, temp);

        temp.pop_back();

        // not pick and move ahead
        fxn(index + 1, target, nums,
            sum,
            ans, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        fxn(0, target, candidates,
            0, ans, temp);

        return ans;
    }
};