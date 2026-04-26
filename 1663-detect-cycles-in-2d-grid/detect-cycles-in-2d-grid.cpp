class Solution {
    int n ,m;
    int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

    // int found (int i,int j,pair<int,int>&prev,vector<vector<char>>& grid,vector<vector<int>>&vis){

    //     pair<int,int> cur = {i,j};
    //     if(vis[i][j] && (cur != prev)) return 1;
    //     vis[i][j] = 1;
    //     bool ok  = 0;
    //     for(auto &d : dir){

    //         int n_r = i + d[0];
    //         int n_c = j + d[1];

    //             if(n_r>=0 && n_r<n && n_c>=0 && n_c<m  && grid[i][j] == grid[n_r][n_c]){

    //                 if(!vis[n_r][n_c]){
    //                     ok  |= found(n_r,n_c,cur,grid,vis);
    //                 }
    //             }
           
    //     }

    //     return ok;
    // }


     int found (int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis){

        using T = tuple<int,int,int,int> ;
        queue<T>q;

        q.push({i,j,-1,-1});
        

        vis[i][j] = 1;

        while(!q.empty()){
            auto [x,y,px,py] = q.front();q.pop();

            for(auto &d : dir){

                int n_r = x + d[0];
                int n_c = y + d[1];

                if(n_r<0 || n_r>= n || n_c<0 || n_c>=m)continue;

                if(grid[n_r][n_c] != grid[x][y])continue;

                if(n_r == px && n_c == py) continue;

                if(vis[n_r][n_c])  return true;

                q.push({n_r,n_c,x,y});
                vis[n_r][n_c] = 1;

            }
        }

        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        
       n  = grid.size(),m = grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                
                
                if(!vis[i][j] && found(i,j,grid,vis)) return true;
            }
        }

        return false;


    }
};