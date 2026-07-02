class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n;
    void calculate_dist(int n, vector<vector<int>>& dist,
                        vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // theives
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int n_r = r + dx[k];
                int n_c = c + dy[k];

                if (n_r >= 0 && n_r < n && n_c >= 0 && n_c < n &&
                    dist[n_r][n_c] == -1) {
                    dist[n_r][n_c] = dist[r][c] + 1;
                    q.push({n_r, n_c});
                }
            }
        }
    }

    bool valid(int n, int d, vector<vector<int>>& dist,vector<vector<int>>& vis) {

        queue<pair<int, int>> q;

        if (dist[0][0] < d)
            return false; // hm nhi ja skte yha se

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int n_r = r + dx[k];
                int n_c = c + dy[k];

                if (n_r >= 0 && n_r < n && n_c >= 0 && n_c < n && !vis[n_r][n_c] &&dist[n_r][n_c] >= d) {
                    vis[n_r][n_c] = 1;
                    q.push({n_r, n_c});
                }
            }
        }

        return false;
    }

public:

       
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));

        calculate_dist(n, dist, grid);

        

        

        int mx_dist = 0;
        

        int l = 0, r = 1e8;
        while (l <= r) {
            int mid = l + (r - l) / 2;
             vector<vector<int>> vis(n, vector<int>(n,false));
            if (valid(n, mid, dist,vis)) {
                mx_dist = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return mx_dist;
    }
};