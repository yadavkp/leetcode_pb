
// #define ll long long 
// class Solution {
//     int n;
//     int solve(int i,int amount,vector<int>&coins, int cnt){

//         if(amount == 0){
//             return 0;
//         }
//         if(i >= n) return 1e7;
//        if(amount < 0) return 1e7;

//         int take = 1e7;
//         if(amount - coins[i] >= 0){
//              take = 1 + solve(i,amount - coins[i],coins, cnt+1);
//         }

//         cout << "i=" << i << " amount=" << amount << " cnt=" << cnt << "\n";

//         int not_take = solve(i+1,amount,coins, cnt);

//         return min(take , not_take);
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//        n = coins.size();
//        if(amount == 0)return 0;
       
//        //if(sum < amount)return -1;
//        int ans = solve(0,amount,coins, 0);
//       return (ans == 1e7 ? -1 : ans);
//     }
// };

#define ll long long 
class Solution {
    int n;
    vector<vector<int>> dp;
    int solve(int i,int amount,vector<int>&coins){

        if(amount == 0){
            return 0;
        }
        
       if(amount < 0 || i >= n) return 1e7;

        if(dp[i][amount] != -1)return dp[i][amount];
        
        int take = 1e7; // suppose this u have taken start coin
        if(amount - coins[i] >= 0){
             take = 1 + solve(i,amount - coins[i],coins);
        }
        int not_take = solve(i+1,amount,coins);
        
        return dp[i][amount] = min(take , not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       n = coins.size();
       if(amount == 0)return 0;
       dp.assign(n,vector<int>(amount+1,-1));
       int ans = solve(0,amount,coins);
      return (ans == 1e7 ? -1 : ans);
    }
};