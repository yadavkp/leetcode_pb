// class Solution {
// public:
//     int lengthOfLIS(vector<int>& a) {
        
//         int n = a.size();
//         vector<int> d(n,1);
//         for(int i=1;i<n;i++){
//             for(int j = 0;j<i;j++){
//                 if(a[j] < a[i]){
//                     d[i] = max(d[i],d[j]+1);
//                 }
//             }
//         }
//         int ans = d[0];
//         for(int i=1;i<n;i++){
//             ans = max(ans,d[i]);
//         }
//         return ans;
//     }
// };




class Solution {
    int n;
    vector<vector<int>> dp;

    int solve(int i, int prev, vector<int>& nums) {
        if(i == n) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        // not take
        int notTake = solve(i+1, prev, nums);

        // take
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i+1, i, nums);
        }

        return dp[i][prev+1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(n+1, -1));
        return solve(0, -1, nums);
    }
};
