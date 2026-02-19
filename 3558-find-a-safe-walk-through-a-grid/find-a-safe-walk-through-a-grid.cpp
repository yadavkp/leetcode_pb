class Solution {
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int n = grid.size(),m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,-1));

        queue<vector<int>> q;
        if(grid[0][0]==1)health--;
        q.push({0,0,health});

        vis[0][0] = health;

        while(!q.empty()){

            auto vec = q.front(); q.pop();

            int r = vec[0],c = vec[1],rem_h = vec[2];

            if(r == n-1 && c == m-1 && rem_h >= 1){
                return true;
            }

            for(int i=0;i<4;i++){
                int n_r = r + dx[i];
                int n_c = c + dy[i];

                if(n_r>=0 && n_r< n && n_c >= 0 && n_c < m ){

                    int next_h = rem_h - grid[n_r][n_c];

                    if(next_h >= 1 && next_h > vis[n_r][n_c]){
                        vis[n_r][n_c] = next_h;
                        q.push({n_r,n_c,next_h});
                    } 
                }
            }
        }

        return false;

    }
};