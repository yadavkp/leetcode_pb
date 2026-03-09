class Solution {
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        

        int n = image.size(),m = image[0].size();
        queue<pair<int,int>> q;
        
        
        q.push({sr,sc});
        int st = image[sr][sc];
        image[sr][sc] = color;

        if(st == color) return image;

        while(!q.empty()){

            auto [r,c] = q.front(); q.pop();

            for(int i=0;i<4;i++){
                int n_r = r + dx[i];
                int n_c = c + dy[i];

                if(n_r >=0 && n_r<n && n_c >=0 && n_c < m && image[n_r][n_c]==st){
                    q.push({n_r,n_c});
                    image[n_r][n_c] = color;
                }
            }
        }

        return image;
    }
};


