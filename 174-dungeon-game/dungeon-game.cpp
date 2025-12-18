
// //recursion ->>>>>>>>>>>

// class Solution {
   
//     vector<vector<int>> dp;
//     int path(int r, int c, vector<vector<int>>& dun) {
//         int n = dun.size(), m = dun[0].size();
//         if (r >= n || c >= m) return 1e9; // out of bounds

//         if (r == n-1 && c == m-1) {
//             if(dun[r][c] <= 0) return abs(dun[r][c])+1; // for survive
//              return 1;
//         }

//         int down = path(r+1, c, dun);
//         int right = path(r, c+1, dun);

//         int need = min(down, right) - dun[r][c];
        
//         return (need <= 0 ? 1 : need);
//     }

// public:
//     int calculateMinimumHP(vector<vector<int>>& dun) {
//         int n = dun.size();
//         int m = dun[0].size();
      
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

        // Fill rest of the table
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                // base case pick by recursion 
                if(i == n-1 && j == m-1){
                    if(dun[i][j] > 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = abs(dun[i][j]) + 1;
                    }
                }else{
                     int down = (i+1 >= n ? 1e9 : dp[i+1][j]);
                    int right = (j+1 >= m ? 1e9 : dp[i][j+1]);
                    int need = min(down,right) - dun[i][j];
                    dp[i][j] = (need <=0 ? 1 :  need );
                }
               
            }
        }

        return dp[0][0];
    }
};


