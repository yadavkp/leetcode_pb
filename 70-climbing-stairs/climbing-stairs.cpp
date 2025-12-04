// class Solution {
    
//     int  solve(int n,vector<int>&dp){

//         if(n < 0 ){
//             return 0;
//         }
      
//         if(n == 0){
//             return  dp[n] + 1;
//         }

//         if(dp[n] != -1){
//             return dp[n];
//         }
//         dp[n] = solve(n-1,dp)  + solve(n-2,dp);
//         return dp[n];

//     }
// public:
//     int climbStairs(int n) {
//         vector<int> dp(50,-1);
//         dp[0] = 0;
//         // int ans = solve(n,dp);
//         return solve(n,dp);
//     }
// };


// by bottom to up  appraoch -> 

class Solution {
    int  solve(int n,int i,vector<int>&dp){

        if(i > n ){
            return 0;
        }
      
        if(i == n){
            return   1;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        dp[i] = solve(n,i+1,dp)  + solve(n,i+2,dp);
        return dp[i];

    }
public:
    int climbStairs(int n) {
        vector<int> dp(50,-1);

        //dp[0] = 0;
        
        return solve(n,0,dp);
    }
};