

// flag ==0,  neutral
// flag = 1 ,to ab sell krna hi hai

vector<vector<int>> dp;

class Solution {

    int solve(int i,int flag,vector<int>&price){

        if(i >= price.size())return 0;

        if(dp[i][flag] != -1)return dp[i][flag];
        int buy = 0,sell = 0;

        if(flag ==0){
            int take = - price[i] + solve(i+1,1,price);
            int not_take = 0 + solve(i+1,0,price);
            buy =  max(take,not_take);

        }

        if(flag==1){
            int take = price[i] + solve(i+2,0,price);
            int not_take = solve(i+1,1,price);
            sell =  max(take,not_take);
        }

        return dp[i][flag] =  max(buy,sell);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.assign(n,vector<int>(2,-1));

       int profit = solve(0,0,prices);

       return profit;
    }
};
