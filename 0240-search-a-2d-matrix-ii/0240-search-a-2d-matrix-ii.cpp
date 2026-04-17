class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int i=0;
       int x=target;
        int j=matrix[0].size()-1;
        while(i<matrix.size()&& j>=0){
            if(matrix[i][j]==x){
                return 1;
            }
            else if(matrix[i][j]>x){
                j--;
            }
            else if(matrix[i][j]<x){
                i++;
            }
        }
        return 0;
        
    }
};