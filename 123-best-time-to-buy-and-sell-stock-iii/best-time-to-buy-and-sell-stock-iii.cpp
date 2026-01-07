// class Solution {
//     vector<vector<vector<int>>> dp;
//     int solve(int i,int flag,int limit,vector<int>&price){

//         if(i >= price.size() || limit==0) return 0;
//         int buy = 0,sell = 0;

//         if(dp[i][flag][limit] != -1)return dp[i][flag][limit];

        // if(flag==0){
        //     int take = -price[i] + solve(i+1,1,limit,price);
        //     int not_take = solve(i+1,0,limit,price);
        //     buy = max(take,not_take);
        // }
        // if(flag==1){
        //     int take = price[i] + solve(i+1,0,limit-1,price);
        //     int not_take = solve(i+1,1,limit,price);
        //     sell = max(take,not_take);
        // }

//         return dp[i][flag][limit] =  max(buy,sell);
//     }

// public:
//     int maxProfit(vector<int>& prices) {
        
//         int n = prices.size();
//         dp.assign(n,vector<vector<int>>(2,vector<int>(3,-1)));
//         int profit = solve(0,0,2,prices);

//         return profit;
//     }
// };


// tabulatin -> of the given pb=->>

class Solution {
    vector<vector<vector<int>>> dp;
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        dp.assign(n+1,vector<vector<int>>(2,vector<int>(3,0)));
       
        for(int i = n-1;i >= 0;i--){
            for(int flag = 0;flag <= 1;flag++){
                for(int limit =2;limit>0;limit--){

                     if(flag==0){
                        int take = -prices[i] + dp[i+1][1][limit]; 
                        int not_take = dp[i+1][0][limit];
                        dp[i][flag][limit] = max(take,not_take);
                     }
                    if(flag==1){
                        int take = prices[i] + dp[i+1][0][limit-1]; 
                        int not_take = dp[i+1][1][limit];
                        dp[i][flag][limit] = max(take,not_take);
                    }
                }
            }
        }

        return dp[0][0][2];

    }
};
