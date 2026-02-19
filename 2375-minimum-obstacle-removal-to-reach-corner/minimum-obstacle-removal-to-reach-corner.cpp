class Solution {
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        

        int n = grid.size(),m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,1e6));

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > pq;
        if(grid[0][0]==1)pq.push({1,0,0}),vis[0][0]=1; // pay initial cost
        else pq.push({0,0,0}),vis[0][0]=0;


        while(!pq.empty()){

            auto vec = pq.top(); pq.pop();

            int old_cost = vec[0],r = vec[1],c = vec[2];

            if(r == n-1 && c == m-1){
                return old_cost;
            }

            for(int i=0;i<4;i++){
                int n_r = r + dx[i];
                int n_c = c + dy[i];

                if(n_r>= 0 && n_r < n && n_c >= 0 && n_c < m ){

                    int new_cost = grid[n_r][n_c] + old_cost;

                    if(new_cost < vis[n_r][n_c]){
                        vis[n_r][n_c] = new_cost;
                        pq.push({new_cost,n_r,n_c});
                    }
                }
            }
        }

        return m+n-1;

    }
};