class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //first lets take transpose
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // then reverse the matrix;
        int l = 0;
        int r = n-1;
        int i = 0;

        while(r>l){
            for(int i = 0; i<n; i++){
                swap(matrix[i][l],matrix[i][r]);
            }
            l++;
            r--;
        }
        
    }
};