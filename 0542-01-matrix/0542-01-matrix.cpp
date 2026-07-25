class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols,-1));
        queue<pair<int,int>> q;
        for(int row = 0; row<rows; row++){
            for(int col = 0; col<cols; col++){
                if(mat[row][col] == 0){
                    dist[row][col] = 0;
                    q.push({row,col});
                }
            }
        }

        int dr [] = {-1,0,1,0};
        int dc [] = {0,1,0,-1};
        
        while(!q.empty()){
            int rowa = q.front().first;
            int cola = q.front().second;
            q.pop();
            for(int i =0; i<4; i++){
                int newr = rowa+dr[i];
                int newc = cola+dc[i];

                if(newr<rows && newr>= 0 && newc>=0 && newc<cols && dist[newr][newc] == -1){
                    dist[newr][newc] = dist[rowa][cola] + 1;
                    q.push({newr, newc});
                }
            }
        }

        return dist;
    }
};