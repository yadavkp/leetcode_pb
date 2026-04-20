class Solution {
   // vector<vector<vector<int>>> dp;
    int dp[1002][2][101];
    int solve(int i,int flag,int limit,vector<int>&price){

        if(i >= price.size() || limit==0) return 0;
        int buy = 0,sell = 0;

        if(dp[i][flag][limit] != -1)return dp[i][flag][limit];

        if(flag==0){
            int take = -price[i] + solve(i+1,1,limit,price);
            int not_take = solve(i+1,0,limit,price);
            buy = max(take,not_take);
        }
        if(flag==1){
            int take = price[i] + solve(i+1,0,limit-1,price);
            int not_take = solve(i+1,1,limit,price);
            sell = max(take,not_take);
        }

        return dp[i][flag][limit] =  max(buy,sell);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //dp.assign(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        memset(dp,-1,sizeof(dp));
        return solve(0,0,k,prices);
    }
};


    