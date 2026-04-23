class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        string ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k--) st.pop();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty()) return "0";
        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;
        string v=ans.substr(i,ans.size()-i);
        if(v.empty()) return "0";
        return v;
    }
};