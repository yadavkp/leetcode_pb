// class Solution {
//     int n;
//     int solve(int i,int amount,vector<int>& coins){

//         if(amount == 0){
//             return 1;
//         }

//         if(amount < 0 || i == n)return 0;
//         // either we take and stay on the curr idx
//         // or skip that curr idx and go to the other idx
//         int take = solve(i,amount- coins[i],coins);
//         int not_take = solve(i+1,amount,coins);

//         return  take + not_take;
//     }


// public:
//     int change(int amount, vector<int>& coins) {
//         n = coins.size();
//         if(amount==0)return 1;
//         return solve(0,amount,coins);
//     }
// };



// memoisation  ->>>>>>>>>>>>

// class Solution {
//     int n;
//     vector<vector<int>> dp;
//     int solve(int i,int amount,vector<int>& coins){

//         if(amount == 0){
//             return 1;
//         }

//         if(amount < 0 || i == n)return 0;
//         // either we take and stay on the curr idx
//         // or skip that curr idx and go to the other idx
//         if(dp[i][amount] != -1)return dp[i][amount];

//         int take = solve(i,amount- coins[i],coins);
//         int not_take = solve(i+1,amount,coins);

//         return dp[i][amount] = take + not_take;
//     }


// public:
//     int change(int amount, vector<int>& coins) {
//         n = coins.size();
//         if(amount==0)return 1;
//         dp.assign(n+1,vector<int>(amount+1,-1));
//         return solve(0,amount,coins);
//     }
// };



// 
#define ll unsigned long long
class Solution {
    ll n;
public:
    ll change(int amount, vector<int>& coins) {
        n = coins.size();
        if(amount==0)return 1;
        vector<vector<ll>> dp(n+1,vector<ll>(amount+1,0));
        // base case
        // for each idx if amount is 0 , we will make 1

        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }

        dp[n][amount] = 0;
        for(int i = n-1;i >= 0;i--){
            for(int sum = 1;sum <=amount;sum++){
                ll take = 0;
                if(sum - coins[i] >=0){
                     take = dp[i][sum - coins[i]];
                }
                ll not_take = dp[i+1][sum];

                dp[i][sum] = take + not_take;
            }
        }

        return dp[0][amount];

    }
};