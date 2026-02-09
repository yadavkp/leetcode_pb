class Solution {
int n,m; 
queue<pair<int,int>> q;
vector<vector<bool>> vis;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool valid(int i,int j){

    if(i < 0 || j  < 0 || i >= n || j >= m || vis[i][j]== true)return false;


    return true;
}

void dfs(int i,int j,vector<vector<int>>& mat){

    vis[i][j] = true;
    q.push({i,j});

    for(int k =0;k<4;k++){
        int n_r = i + dx[k];
        int n_c = j + dy[k];

        if(valid(n_r,n_c)){
            if(mat[n_r][n_c]  == 1){
                dfs(n_r,n_c,mat);
            }
        }
    }
}

public:
    int shortestBridge(vector<vector<int>>& mat) {
        
        n = mat.size();
        m = mat[0].size();
        vis.assign(n,vector<bool>(m,false));
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1){
                    dfs(i,j,mat);
                    found = true;
                    break;
                }
            }
            if(found)break;
        }

       



        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){

                auto [r,c] = q.front();q.pop();

                 for(int k =0;k<4;k++){
                        int n_r = r + dx[k];
                        int n_c = c + dy[k];

                        if(valid(n_r,n_c)){

                            if(mat[n_r][n_c] == 1)return level;
                            q.push({n_r,n_c});
                            vis[n_r][n_c] = true;
                        }
                }
            }
            level++;
        }

        return level;
    }
};