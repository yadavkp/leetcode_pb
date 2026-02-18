class Solution {
    int dx[8] = {0,0,1,-1,-1,-1,1,1};
    int dy[8] = {-1,1,0,0,-1,1,1,-1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size(),m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)return -1;
        queue<pair<int,int>> q;
        q.push({0,0});

        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        int len = 0;

        auto valid = [&](int r,int c){

            if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] == 1 || grid[r][c]==1) return false;
            return true;

        };

        bool got  = false;
        while(!q.empty()){

            int sz = q.size();
            bool found = false;
            while(sz--){

                auto [r,c] = q.front() ; q.pop();

                    if(r == n-1 && c == m-1){
                        len  = len+1;
                        return len;
                        break;
                    }

                    for(int i=0;i<8;i++){

                        int n_r =  r + dx[i];
                        int n_c  = c + dy[i];

                        if(valid(n_r,n_c)){
                            q.push({n_r,n_c});
                            vis[n_r][n_c] = 1;
                        }
                    }
                    
        
            }
            if(found)break;
            len++;
        }

        return -1;
    }
};