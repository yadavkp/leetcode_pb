class Solution {

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        queue<pair<int,int>> q;

        for(int r=0;r<n;r++){
            for(int c = 0; c<m;c++){

                if(mat[r][c] == 0)q.push({r,c});
                else mat[r][c] = -1;
            }
        }

         while(!q.empty()){

                    auto [ro,co] = q.front();
                    q.pop();

                    for(int i=0;i<4;i++){
                        int n_r = ro + dx[i];
                        int n_c = co + dy[i];

                        if(n_r < 0 || n_c < 0 || n_r >=n || n_c >= m || mat[n_r][n_c] != -1)continue;

                        // process only those have -1 bale negihbour;

                        mat[n_r][n_c] = mat[ro][co] + 1;

                        q.push({n_r,n_c});


                    }
                }

        return mat;
    }
};