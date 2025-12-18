// #define ll long long 
// class Solution {
//     ll dp[1001][501][3];

//     ll solve(int i,int k,int type,vector<int>&price){

//         if(i == price.size()){
//             if(type == 0) return 0; // means all k transation done
//             return INT_MIN;  // means some trasn not completed;
//         }
        

//         ll dont_take;
//         ll take = INT_MIN;
//         dont_take = solve(i+1,k,type,price);
        
//         if(k > 0){
//             if(type == 1){
//                 // we need to sell;
//                 take = price[i] + solve(i+1,k-1,0,price);// 0 ->  we will start freshtransn;
//             }else if(type == 2){
//                 // we need to buy;
//                 take = -price[i] + solve(i+1,k-1,0,price);
//             }else{
//                 // same idx pr buy bhi kiya aur sell bhi kia
//                 // buy to sell -> 
//                 take = max(-price[i] + solve(i+1,k,1,price), price[i] + solve(i+1,k,2,price));
//             }
//         }

//         return max(take,dont_take);
//     }

// public:
//     long long maximumProfit(vector<int>& prices, int k) {
//         int n = prices.size();

//         for(int i=0;i<n;i++){
//             for(int j = 0;j<=k;j++){
//                 for(int l = 0;l < 3;l++){
//                     dp[i][j][l] = INT_MIN;
//                 }
//             }
//         }

//         return solve(0,k,0,prices);
//     }
// };


//->>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// memoisation ->>>>>>>>>>>>>>>>>>>>
// #define ll long long 
// class Solution {
//     ll dp[1001][501][3];

//     ll solve(int i,int k,int type,vector<int>&price){

//         if(i == price.size()){
//             if(type == 0) return 0; // means all k transation done
//             return INT_MIN;  // means some trasn not completed;
//         }
        
//         if(dp[i][k][type] != INT_MIN){
//             return dp[i][k][type];
//         }
//         ll dont_take;
//         ll take = INT_MIN;
//         dont_take = solve(i+1,k,type,price);
        
//         if(k > 0){
//             if(type == 1){
//                 // we need to sell;
//                 take = price[i] + solve(i+1,k-1,0,price);// 0 ->  we will start freshtransn;
//             }else if(type == 2){
//                 // we need to buy;
//                 take = -price[i] + solve(i+1,k-1,0,price);
//             }else{
//                 // same idx pr buy bhi kiya aur sell bhi kia
//                 // buy to sell -> 
//                 take = max(-price[i] + solve(i+1,k,1,price), price[i] + solve(i+1,k,2,price));
//             }
//         }

//         return dp[i][k][type] = max(take,dont_take);

//     }

// public:

//     long long maximumProfit(vector<int>& prices, int k) {
//         int n = prices.size();

//         for(int i=0;i<n;i++){
//             for(int j = 0;j<=k;j++){
//                 for(int l = 0;l < 3;l++){
//                     dp[i][j][l] = INT_MIN;
//                 }
//             }
//         }

//         return solve(0,k,0,prices);
//     }
// };


// ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// tabulation - >>>>>>>>
#define ll long long
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        static ll dp[1001][501][3];  // +1 for boundary safety

        for (int i = n; i >= 0; i--) {
            for (int trans = 0; trans <= k; trans++) {
                for (int type = 0; type < 3; type++) {

                    if (i == n) {
                        dp[i][trans][type] = (type == 0 ? 0 : INT_MIN);
                        continue;
                    }

                    ll dont_take = dp[i+1][trans][type];
                    ll take = INT_MIN;

                    if (trans > 0) {
                        if (type == 1) {
                            take = prices[i] + dp[i+1][trans-1][0];
                        } else if (type == 2) {
                            take = -prices[i] + dp[i+1][trans-1][0];
                        } else {
                            take = max(-prices[i] + dp[i+1][trans][1],
                                       prices[i] + dp[i+1][trans][2]);
                        }
                    }

                    dp[i][trans][type] = max(take, dont_take);
                }
            }
        }

        return dp[0][k][0];
    }
};