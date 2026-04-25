class Solution {
    int n;
    int dp[301][5005];
    int solve(int i,int amount,vector<int>& coins){

        if(amount == 0) return 1;

        if(i >= n) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];
        int not_take = solve(i+1,amount,coins);

        int take = 0;
        if(amount >= coins[i]){
           take = solve(i,amount-coins[i],coins);
        }

        return dp[i][amount] =  take + not_take;

    }
public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(dp,-1,sizeof(dp));

        return solve(0,amount,coins);
    }
};