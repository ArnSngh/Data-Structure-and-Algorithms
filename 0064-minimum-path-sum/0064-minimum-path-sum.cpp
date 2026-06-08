class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<int> prev(col, 0);

        for(int r = 0; r < row; r++) {

            vector<int> curr(col, 0);

            for(int c = 0; c < col; c++) {

                if(r == 0 && c == 0) {
                    curr[c] = grid[0][0];
                    continue;
                }

                int left = 1e9;
                int up = 1e9;

                if(c > 0)
                    left = grid[r][c] + curr[c-1];

                if(r > 0)
                    up = grid[r][c] + prev[c];

                curr[c] = min(left, up);
            }

            prev = curr;
        }

        return prev[col-1];
    }
};