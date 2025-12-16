// first here wwe will soved by recursion 
// here we are going to the down to the top not by the top to the botom 
// class Solution {

//     int path(int r,int c,vector<vector<int>>& grid){
//         if(r == 0 && c == 0 && grid[r][c]==0)return 1;

//         if(r < 0 || c < 0 || grid[r][c] == 1)return 0;

//         int left = path(r,c-1,grid);
//         int up = path(r-1,c,grid);

//         return left + up;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
//         int n = Grid.size(), m = Grid[0].size();
//         return path(n-1,m-1,Grid);
//     }
// };


// memoisation  ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// class Solution {
//     vector<vector<int>> dp;
//     int path(int r,int c,vector<vector<int>>& grid){
//         if(r == 0 && c == 0 && grid[r][c]==0)return 1;

//         if(r < 0 || c < 0 || grid[r][c] == 1)return 0;

//         // checking krbake jao 
//         if(dp[r][c] != -1){
//             return dp[r][c];
//         }
//         int left = path(r,c-1,grid);
//         int up = path(r-1,c,grid);

//         return    dp[r][c] =  left + up;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
//         int n = Grid.size(), m = Grid[0].size();
//         dp.assign(n,vector<int>(m,-1));
//         return path(n-1,m-1,Grid);
//     }
// };


//tabulation  ->>>>>>>>>>>>>>>>
/// ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


class Solution {
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size(), m = Grid[0].size();
        vector<vector<int>> dp;
        dp.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j = 0; j <  m ; j++){
                if(i == 0 && j == 0 && Grid[i][j] == 0)dp[i][j] = 1;
                else{
                    int top = 0,left= 0;
                    if(i > 0) top += dp[i-1][j];
                    if(j > 0) left += dp[i][j-1];
                    if(Grid[i][j] != 1){
                        dp[i][j] = top + left;
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};