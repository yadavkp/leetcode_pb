
// recursion ->>>>>>>>>>>

// class Solution {
   
//     vector<vector<int>> dp;
//     int path(int r, int c, vector<vector<int>>& dun) {
//         if (r >= n || c >= m) return 1e9; // out of bounds

//         if (r == n-1 && c == m-1) {
//             return max(1, 1 - dun[r][c]); // base case
//         }

//         int down = path(r+1, c, dun);
//         int right = path(r, c+1, dun);

//         int need = min(down, right) - dun[r][c];
//         return  max(1, need);
//     }

// public:
//     int calculateMinimumHP(vector<vector<int>>& dun) {
//         n = dun.size();
//         m = dun[0].size();
      
//         int ans = path(0, 0, dun);
//         return ans;
//     }
// };


//Memoisation ->>>>>>>>>>>>>.
//->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// class Solution {
//     int n, m;
//     vector<vector<int>> dp;
//     int path(int r, int c, vector<vector<int>>& dun) {
//         if (r >= n || c >= m) return 1e9; // out of bounds

//         if (r == n-1 && c == m-1) {
//             return max(1, 1 - dun[r][c]); // base case
//         }

//         if(dp[r][c] != -1)return dp[r][c];

//         int down = path(r+1, c, dun);
//         int right = path(r, c+1, dun);

//         int need = min(down, right) - dun[r][c];
//         return dp[r][c] = max(1, need);
//     }

// public:
//     int calculateMinimumHP(vector<vector<int>>& dun) {
//         n = dun.size();
//         m = dun[0].size();
//         dp.assign(n,vector<int>(m,-1));
//         int ans = path(0, 0, dun);
//         return ans;
//     }
// };



//->>>>>>>>>>>>>>>>>>>>
// tabulation ->>>>>>>>>>>>>>>>>>>>>.

class Solution {
    int n, m;
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        n = dun.size();
        m = dun[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Base case: destination cell
        dp[n-1][m-1] = max(1 , 1 - dun[n-1][m-1]);

        // Fill last row
        for(int j = m-2; j >= 0; j--) {
            dp[n-1][j] = max(1, dp[n-1][j+1] - dun[n-1][j]);
        }

        // Fill last column
        for(int i = n-2; i >= 0; i--) {
            dp[i][m-1] = max(1, dp[i+1][m-1] - dun[i][m-1]);
        }

        // Fill rest of the table
        for(int i = n-2; i >= 0; i--) {
            for(int j = m-2; j >= 0; j--) {
                int down = dp[i+1][j];
                int right = dp[i][j+1];
                dp[i][j] = max(1, min(down, right) - dun[i][j]);
            }
        }

        return dp[0][0];
    }
};