// class Solution {
// public:
//     int rob(vector<int>& a) {
//         // we will solve this pb by dep, with O(1 space complexity)
//     int n = a.size();
//         int prev1 = a[0];
//         int prev2 = 0;
//         int money = 0;
//         for(int i=1;i<n;i++){

//             int rob = a[i];
//             if(i > 1) rob += prev2;

//             int not_rob = prev1;

//             money = max(rob,not_rob);
//             prev2 = prev1;
//             prev1 = money;

//         }
//         return prev1;
//     }
// };

// by recursion it give tle -> 
// so optimise by memoisaton 
class Solution {
    vector<int> dp;
    int f(int i,vector<int>&a){
        if(i==0) return a[0];
        if(i < 0) return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = max(a[i] + f(i-2,a), f(i-1,a));
    }
public:
    int rob(vector<int>& a) {
        // we will solve this pb by dep, with O(1 space complexity)
        
        int n = a.size();
        dp.assign(n,-1);
        return f(n-1,a);
    }
};