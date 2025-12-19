// class Solution {

//     int solve(int idx,int n,vector<int>& a){

//         // bc
//         if(idx == 0 && n ==0) return a[0]; // if only one house we can rob them
//         if(idx >= n) return 0;

//         int sum = 0;
//         int take = a[idx] + solve(idx+2,n,a);
//         int dont_take = solve(idx+1,n,a);

//         sum += max(take,dont_take);
//         return  sum;

//     }
// public:
//     int rob(vector<int>& a) {
//         int n = a.size();
       
       
//         int ans = max(solve(1,n,a),solve(0,n-1,a));
    
//         return ans;
    
//     }
// };


// memoisation  ->>>>>>>>>>>>>>>>>>>>..
class Solution {
    vector<int> dp;
    int solve(int idx,int n,vector<int>& a){

        // bc
        if(idx == 0 && n ==0) return a[0]; // if only one house we can rob them
        if(idx >= n) return 0;

        if(dp[idx] != -1)return dp[idx];
        int sum = 0;
        int take = a[idx] + solve(idx+2,n,a);
        int dont_take = solve(idx+1,n,a);

        sum += max(take,dont_take);
        return  dp[idx] = sum;

    }
public:
    int rob(vector<int>& a) {
        int n = a.size();
       
        dp.assign(n,-1);
        int ans1 = solve(1,n,a);
        dp.assign(n-1,-1);
        int ans2 = solve(0,n-1,a);
        
        return max(ans1,ans2);
    
        
    
    }
};