// class Solution {
//     int dx[4] = {0,0,-1,1};
//     int dy[4] = {-1,1,0,0};
//     int n,m;

//     vector<vector<int>> dp;
//     int solve(int r,int c,vector<vector<int>>& mat){

//         if(r < 0 || r >=n || c < 0 || c >= m) return 0;


//         if(dp[r][c] != -1){
//             return dp[r][c];
//         }

//         int cnt = 0;
//         int left=0,right=0,up=0,down=0;
//         // left,
//         if(c > 0  && mat[r][c-1] > mat[r][c]){
//             left = 1 + solve(r,c-1,mat);
            
//         } 
//         if(r >0 && mat[r-1][c] > mat[r][c] ){
//             up = 1 + solve(r-1,c,mat);
            
//         } 
//         if(c+1 <m && mat[r][c+1] > mat[r][c]){
//             right = 1 + solve(r,c+1,mat);
            
//         } 
        
//         if(r+1 < n && mat[r+1][c] > mat[r][c]){
//             down = 1 + solve(r+1,c,mat);
            
//         }
        
//         // for(int i = 0;i<4;i++){
//         //     int n_r = r + dx[i];
//         //     int n_c = c + dy[i];

//         //     if(mat[n_r][n_c] > mat[r][c]){
//         //         cnt += 1 + solve(n_r,n_c,prev,mat);
//         //     }
//         //     cout<<cnt<<"\n";
//         // }
        
//         //cout<<cnt<<"\n";
//         cnt = max({up,left,right,down});
//         return dp[r][c] =  cnt;

//     }

// public:
//     int longestIncreasingPath(vector<vector<int>>& mat) {
        
//          int ans = 0;
//         n = mat.size(),m = mat[0].size();
//         dp.assign(n,vector<int>(m,-1));
//          for(int i=0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                // cout<<i<<" "<<j;
//                ans = max(ans,solve(i,j,mat));
//             }
//          }

//          return ans+1;
         
//     }
// };


// best way to recursion +memoisation



class Solution {
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int n,m;

     vector<vector<int>> dp;
    int solve(int r,int c,vector<vector<int>>& mat){
 

        int cnt = 0;
        
        if(dp[r][c]  != -1)return dp[r][c];

        for(int i = 0;i<4;i++){

            int n_r = r + dx[i];
            int n_c = c + dy[i];

            if((n_r >=0 && n_r < n) && (n_c >= 0 && n_c < m ) && mat[n_r][n_c] > mat[r][c]){
                cnt =  max(cnt,1 + solve(n_r,n_c,mat));
            }

            
        }
        return dp[r][c] = cnt;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int ans = 0;
        n = mat.size(),m = mat[0].size();
        dp.assign(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
           
               ans = max(ans,solve(i,j,mat));
            }
        }

        return ans+1;
         
    }
};