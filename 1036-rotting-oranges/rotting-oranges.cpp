class Solution {
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};



    bool valid(int r,int c,int n,int m,vector<vector<int>>&grid){
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 2||
        grid[r][c] == 0 )return false;

        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int one = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1)one++;
            }
        }

        int cnt =0;
        if(one == 0) return 0;
        
        if(q.empty()) return -1; // no 2, but one present

       
 
        while(!q.empty()){

            int sz = q.size();

            while(sz--){

                auto [r,c] = q.front();q.pop();
                for(int i = 0;i<4;i++){
                    int n_r = r + dx[i];
                    int n_c = c + dy[i];
                    if(valid(n_r,n_c,n,m,grid)){
                        q.push({n_r,n_c});
                        grid[n_r][n_c] = 2;
                        one--;
                    }
                }
            }
            cnt++;
        }

        return (one == 0 ? cnt-1 : -1);
    }
};