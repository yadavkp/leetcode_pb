class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n, m;
    vector<vector<bool>> vis;
    queue<pair<int, int>> q;

    bool valid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]);
    }

    void dfs(int r, int c, vector<vector<int>>& grid) {
        vis[r][c] = true;
        q.push({r, c});
        for (int k = 0; k < 4; k++) { // Use 'k' to avoid shadowing
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (valid(nr, nc) && grid[nr][nc] == 1) {
                dfs(nr, nc, grid);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        vis.assign(n, vector<bool>(m, false));

        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    found = true;
                    break;
                }
            }
        }

        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dx[k];
                    int nc = c + dy[k];

                    if (valid(nr, nc)) {
                        if (grid[nr][nc] == 1) return level; // Second island hit!
                        
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            level++;
        }
        return level;
    }
};