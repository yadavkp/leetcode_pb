class Solution {
    #define ll long long 
public:
    int maxSideLength(vector<vector<int>>& mat, int frq) {
        
        int ans = 0;
        int n = mat.size(),m = mat[0].size();

        int mn = 1e7;
        vector<vector<ll>> pfx(n+1,vector<ll>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j = 0; j< m; j++){
                int r = i+1,c = j+1;
                pfx[r][c] += (ll)mat[i][j];
                int left = pfx[r][c-1];
                int down = pfx[r-1][c];
                int sub = pfx[r-1][c-1];
                pfx[r][c] += left + down - sub; 
            }
        }
        
        
       
        
            for(int i=1;i<=n;i++){
                for(int j = 1; j<= m; j++){
                    for(int k = 0;k < min(n,m);k++){

                        if(i + k <= n && j + k <= m){
                            int r2 = i + k,c2 = j +k,r1 = i,c1 = j;
                            ll val = pfx[r2][c2] - pfx[r1-1][c2] - pfx[r2][c1-1] + pfx[r1-1][c1-1];

                            if(val <= frq){
                                ans = max(ans,k+1);
                            }
                        }
                    }
                }    
            }     
       

        return ans;
    }
};