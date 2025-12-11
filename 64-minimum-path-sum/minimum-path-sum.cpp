// class Solution {

//     int ans = INT_MAX;
//     vector<vector<int>> dp;
//     void solve(int r,int c,vector<vector<int>>& grid,int sum){
//         //
//         int m = grid.size(),n = grid[0].size();
//         if(r >= m || c >= n)return;

//         sum += grid[r][c];

//         if(r == m-1 && c == n-1){
//             ans = min(ans,sum);
//             return;
//         }

//         solve(r,c+1,grid,sum);
//         solve(r+1,c,grid,sum);
//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(),n = grid[0].size();
//         dp.assign(m,vector<int>(n,-1));
//         dp[0][0] = grid[0][0];
//         solve(0,0,grid,0);

//         return dp[m-1][n-1];

//         //return ans;
//     }
// };


// class Solution {
//     vector<vector<int>> dp;
//     int solve(int r, int c, vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
        
//         if (r >= m || c >= n) return INT_MAX;
    
//         if (r == m-1 && c == n-1) return grid[r][c];
        
//         if (dp[r][c] != -1) return dp[r][c];
        
//         int right = solve(r, c+1, grid);
//         int down  = solve(r+1, c, grid);
        
       
//         dp[r][c] = grid[r][c] + min(right, down);
//         return dp[r][c];
//     }
    
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         dp.assign(m, vector<int>(n, -1));
//         return solve(0, 0, grid);
//     }
// };


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int r = 0;r < m;r++){
            for(int c = 0;c < n;c++){
                int sum = INT_MAX;
                if(r-1 >= 0){
                    //dp[r-1][c] = min()
                    sum  = min(sum,dp[r-1][c]);
                }

                if(c-1 >= 0){
                    sum = min(sum,dp[r][c-1]);
                }

                dp[r][c] = (sum == INT_MAX ? 0 : sum) + grid[r][c];
            }
        }

        return dp[m-1][n-1];
    }
};