class Solution {
public:
    void gen(vector<string>&ans, string &str, int open, int close,int n){
        if(str.length()==2*n) return ans.push_back(str);
        if(open<n){
            str.push_back('(');
            gen(ans, str, open+1,close, n);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            gen(ans, str, open, close+1,n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str="";
        gen(ans, str, 0, 0,n);
        return ans;
    }
};