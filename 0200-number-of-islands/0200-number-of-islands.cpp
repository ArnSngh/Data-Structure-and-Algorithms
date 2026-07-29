class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols, vector<vector<int>>& vis) {
        vis[r][c] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                grid[nr][nc] == '1' && !vis[nr][nc]) {
                dfs(grid, nr, nc, rows, cols, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    dfs(grid, i, j, rows, cols, vis);
                }
            }
        }

        return count;
    }
};