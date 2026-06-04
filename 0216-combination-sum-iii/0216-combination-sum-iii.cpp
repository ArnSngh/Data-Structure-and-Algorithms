class Solution {
    //calassical pick and not pick probelm..kese pta chla ?....agr merkeo aise subsets bnane hain...to ya to number lo ya na lo
private:
    void solve(int k, int n,int currnum, int sum, vector<int>temp, vector<vector<int>> &ans){
        if(temp.size()==k){
            if(sum == n){
                ans.push_back(temp);
                return;
            }
        }

        if(temp.size()>k || currnum>9 || sum>n ){
            return;
        }

        temp.push_back(currnum);
        solve(k ,n , currnum+1, sum+currnum, temp, ans);
        temp.pop_back();
        solve(k,n,currnum+1, sum, temp, ans);

        
    }




public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>> ans;
        solve(k,n,1,0,temp,ans);
        return ans;
        
    }
};