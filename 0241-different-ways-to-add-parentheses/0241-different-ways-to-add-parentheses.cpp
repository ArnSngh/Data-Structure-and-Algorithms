class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
    
private:
    vector<int> solve(const string& exp) {
        if (exp.length() <= 2) {
            return {stoi(exp)};
        }
        
        vector<int> res;
        for (int i = 0; i < exp.length(); i++) {
            char ch = exp[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> lh = solve(exp.substr(0, i));
                vector<int> rh = solve(exp.substr(i + 1));
                
                for (int j : lh) {
                    for (int k : rh) {
                        int tmp = 0;
                        if (ch == '*') tmp = j * k;
                        else if (ch == '+') tmp = j + k;
                        else tmp = j - k;
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
};