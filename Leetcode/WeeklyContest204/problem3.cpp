
class Solution {
   public:
    bool vis[31][31];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(int x, int y, vector<vector<int>>& grid) {
        vis[x][y] = true;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() ||
                vis[nx][ny] == true || grid[nx][ny] == 0)
                continue;
            dfs(nx, ny, grid);
        }
    }

    int minDays(vector<vector<int>>& grid) {
        int con = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && vis[i][j] == false) {
                    dfs(i, j, grid);
                    con++;
                }
            }
        }

        if (con != 1) return 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;

                    con = 0;
                    memset(vis, false, sizeof(vis));
                    for (int k = 0; k < grid.size(); k++) {
                        for (int l = 0; l < grid[0].size(); l++) {
                            if (grid[k][l] == 1 && vis[k][l] == false) {
                                dfs(k, l, grid);
                                con++;
                            }
                        }
                    }

                    if (con > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};