class Solution {
    int n;
    vector<vector<int>> dp;
    int solve(int i,int amount,vector<int>& coins){

        if(amount == 0){
            return 1;
        }

        if(amount < 0 || i == n)return 0;
        // either we take and stay on the curr idx
        // or skip that curr idx and go to the other idx
        if(dp[i][amount] != -1)return dp[i][amount];

        int take = solve(i,amount- coins[i],coins);
        int not_take = solve(i+1,amount,coins);

        return dp[i][amount] = take + not_take;
    }


public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        if(amount==0)return 1;
        dp.assign(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};