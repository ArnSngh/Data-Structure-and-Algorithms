class Solution {

    void solve(int index,int sum, vector<int> &nums, int k , vector<int> &temp, vector<vector<int>> &ans){

        if(sum== k){
            ans.push_back(temp);
            return;
        }

        if(index == nums.size() || sum> k){
            return;
        }

        temp.push_back(nums[index]);
        solve(index+1, sum+nums[index], nums, k, temp, ans);
        while(index<nums.size()-1 && nums[index+1]==nums[index]){
            index++;
        }
        temp.pop_back();
        solve(index+1, sum, nums, k, temp, ans);

    }



public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        vector<vector<int>> ans;
        solve(0,0,candidates, target, temp, ans);
        return ans;
        
    }
};