class Solution {
    vector<int> dp;

    int  solve(int n,vector<int>&dp){

        if(n < 0 ){
            return 0;
        }
      
        if(n == 0){
            return  1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = solve(n-1,dp)  + solve(n-2,dp);
        return dp[n];

    }
public:
    int climbStairs(int n) {
        vector<int> dp(50,-1);
        dp[0] = 0;
        int ans = solve(n,dp);
        return ans;
    }
};