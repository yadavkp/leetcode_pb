// we will move from down to top, so move will be reverse down -> up,right -> left;

//1 recursion 
// class Solution {
//     int path(int r, int c){

//         // b case 
//         if(r == 0 && c == 0){
//             return 1;
//         }
//         if(r < 0 || c < 0 )return 0;

//         int left = path(r,c-1);
//         int up = path(r-1,c);
        
//         return left + up;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         return path(m-1,n-1);
//     }
// };

// 

// // Memoisaton 
// class Solution {
//     vector<vector<int>> dp;
//     int path(int r, int c){

//         // b case 
//         if(r == 0 && c == 0){
//             return 1;
//         }
        
//         if(r < 0 || c < 0 )return 0;

//         // checking 
//         if(dp[r][c]  != -1)return dp[r][c];

//         int left = path(r,c-1);
//         int up = path(r-1,c);
        
//         return dp[r][c] = left + up;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         dp.assign(m,vector<int>(n,-1));
//         return path(m-1,n-1);
//     }
// };



// tabulation ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.assign(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j = 0; j< n;j++){
                if(i == 0 && j == 0)dp[i][j] = 1;
                else{
                    int left=0,up = 0;
                    if(i>0) up += dp[i-1][j];  // up function 
                    if(j>0) left += dp[i][j-1]; // left function 
                    dp[i][j] = left + up; // sum of both count path
                }
            }
        }
        return dp[m-1][n-1];
    }
};