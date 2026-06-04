class Solution {
private:
    vector<string> mapp = { 
        "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };

    void solve(string digits, int index, string &output, vector<string> &ans){

        if(output.size() == digits.size()){
            ans.push_back(output);
            return;
        }
        string currchar = mapp[digits[index]-'0'];
        for(int i =0; i<currchar.size(); i++){
            output.push_back(currchar[i]);
            solve( digits, index+1, output, ans);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") return {};
        string output = "";
        solve(digits, 0,output,ans);
        return ans;
        
    }
};