class Solution {
public:
    void gen(int n, string s, vector<string>& ans,
             int open, int close) {

        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            gen(n, s + "(", ans, open + 1, close);
        }

        if (close < open) {
            gen(n, s + ")", ans, open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(n, "", ans, 0, 0);
        return ans;
    }
};