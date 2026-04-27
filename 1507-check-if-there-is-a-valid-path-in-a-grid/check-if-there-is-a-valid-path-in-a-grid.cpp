class Solution {
    
    int n,m;
    
    int solve(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid){

    vector<vector<pair<int,int>>> dir(7);
    dir[1] = {{0,-1},{0,1}};
    dir[2] = {{-1,0},{1,0}};
     dir[3] = {{0,-1},{1,0}};
     dir[4] = {{0,1},{1,0}};
     dir[5] = {{0,-1},{-1,0}};
     dir[6] = {{0,1},{-1,0}};



        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){

            auto [r,c] = q.front();q.pop();

             if(r == n-1 && c == m-1) return true;
           
            for(auto [dr,dc] : dir[grid[r][c]]){
               int n_r = r + dr;
               int n_c = c + dc;

                if(n_r<0 || n_r >=n || n_c <0 ||n_c>=m ||vis[n_r][n_c]) continue;

                // check back path is connected or not

                for(auto [ndr,ndc] : dir[grid[n_r][n_c]]){

                    // check is path is connected is two way

                    if(ndr + n_r == r && ndc + n_c == c){
                        vis[n_r][n_c] = 1;
                        q.push({n_r,n_c});
                    }
                }

           }
           

        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size(),m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        return solve(0,0,vis,grid);
        
    }
};