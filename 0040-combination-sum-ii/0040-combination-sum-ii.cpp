class Solution {
public:  
    void solve(int index ,vector<int>& candidates, int target, vector<int>& path ,   vector<vector<int>>& ans){
        
        if(target==0) {
            ans.push_back(path);
            return ;
        }

       for (int i = index; i < candidates.size(); i++) {

            
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            path.push_back(candidates[i]);
           
            solve(i + 1, candidates, target - candidates[i], path, ans);

            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
         vector<vector<int>> ans;
        vector<int> path;
        solve(0, candidates, target ,path, ans);
        return ans;
    }
};