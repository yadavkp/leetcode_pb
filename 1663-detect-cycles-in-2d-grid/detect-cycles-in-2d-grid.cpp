class Solution {
    int n ,m;
    int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

    int found (int i,int j,pair<int,int>&prev,vector<vector<char>>& grid,vector<vector<int>>&vis){

        
        vis[i][j] = 1;
        
        for(auto &d : dir){

            int n_r = i + d[0];
            int n_c = j + d[1];

                if(n_r>=0 && n_r<n && n_c>=0 && n_c<m  && grid[i][j] == grid[n_r][n_c]){

                   if(make_pair(n_r,n_c) != prev){
                     if(vis[n_r][n_c]) return true;

                        pair<int,int> cur = {i,j};
                       if( found(n_r,n_c,cur,grid,vis))return true;
                   }
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
                 pair<int,int> cur = {i,j};
                
                if(!vis[i][j] && found(i,j,cur,grid,vis)) return true;
            }
        }

        return false;


    }
};