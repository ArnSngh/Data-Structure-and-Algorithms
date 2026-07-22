class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int start_color = image[sr][sc];
        if(image[sr][sc] == color){
            return image;
        }
        image[sr][sc] = color;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            for(int i = 0; i<4;i++){
                int nr = r+dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<rows && nc>=0 && nc<cols && image[nr][nc]== start_color){
                    q.push({nr,nc});
                    image[nr][nc] = color;
                }
            }

        }
        return image;

        
    }
};