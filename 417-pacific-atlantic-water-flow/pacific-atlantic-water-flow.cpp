class Solution {
    int n,m;
    // int dx[4] = {0,0,-1,1};
    // int dy[4] = {-1,1,0,0};
    int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
    void dfs(int i,int j,vector<vector<int>>& ht, vector<vector<int>>&ocean){
        
        ocean[i][j] = 1;

        for(auto &d : dir){

            int n_r = i + d[0],n_c = j + d[1];

            if(n_r>=0 && n_r<n && n_c>=0 && n_c<m && !ocean[n_r][n_c] && ht[n_r][n_c] >= ht[i][j]){
                dfs(n_r,n_c,ht,ocean);
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        
        n = ht.size(),m = ht[0].size();

        vector<vector<int>> atl_ocean(n,vector<int>(m,0));
        vector<vector<int>> pac_ocean(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
           
            for(int j = 0;j<m;j++){
                if((i == 0 && j>=0) || (i>=0 && j==0)){
                    dfs(i,j,ht,pac_ocean);
                }
                if((j==m-1 && i>=0) || (i==n-1 && j>=0)){
                    dfs(i,j,ht,atl_ocean);
                }
            }
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(atl_ocean[i][j]==1 && pac_ocean[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

    }
};