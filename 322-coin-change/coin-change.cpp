class Solution {
    int n;
    int dp[13][10004];
    int solve(int i,int amount,vector<int>& coins){

        if(amount == 0) return 0;
        if(i >= n) return INT_MAX;

        if(dp[i][amount] != -1) return dp[i][amount];
        int not_take = solve(i+1,amount,coins);

        int take = INT_MAX;
        if(amount >= coins[i]){
            int res = solve(i,amount-coins[i],coins);
            if(res != INT_MAX){
                take = min(take,1 + res);
            }
        }

        return dp[i][amount] =  min(take,not_take);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(dp,-1,sizeof(dp));
        int res =  solve(0,amount,coins);
        return (res == INT_MAX) ? -1 : res;
    }
};