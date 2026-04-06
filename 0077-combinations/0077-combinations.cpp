/*

    Time Complexity : O(k*nCk), here nCk means the binomial coefficient of picking k elements out of n elements.
    where nCk = C(n,k) = n!/(n−k)!×k!.

    Space Complexity : O(nCk), as stated above the nCk here refers to the binomial coefficient.

    Solved using Array + Backtracking.

*/

class Solution { 
private: 
    void combine(int n, int k, vector<vector<int>> &output, vector<int> &temp, int start){
        if(temp.size() == k){
            output.push_back(temp);
            return;
        }
        for(int i=start; i<=n; i++){
            temp.push_back(i);
            combine(n, k, output, temp, i+1);
            temp.pop_back();
        }
    }     
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> temp;
        combine(n, k, output, temp, 1);
        return output;
    }
};