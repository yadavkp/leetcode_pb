// class Solution {
//     vector<vector<int>> dp;
//     //int dp[500][500];
//     int solve(int i,int j,string &s){

//         if(i >= j)return 0;

//         if(dp[i][j] != -1)return dp[i][j];
      
//         if(s[i] == s[j]){
//             return dp[i][j] =  solve(i+1,j-1,s); // store data what i count here
//         }else{
      
//              return dp[i][j] = 1 + min(solve(i,j-1,s),solve(i+1,j,s));
//         }
    

//     }
// public:
//     int minInsertions(string s) {
//         int n = s.size();
//         dp.assign(n,vector<int>(n,-1));
//        //memset(dp,-1,sizeof(dp));
//         int ans = solve(0,n-1,s);

//         return ans;

//     }
// };



// tabulation 

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        //dp.assign(n,vector<int>(n,-1));
        int dp[n][n];
       memset(dp,0,sizeof(dp));
        // base case

        for(int i=n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                //if(i >= j) dp[i][j]  = 0;
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];

    }
};