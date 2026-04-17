class Solution {
     int dp[101];
    int solve(int i,int j,vector<int>&a){


        if(i > j) return 0;
        if(dp[i] != -1) return dp[i];
        int take = a[i] + solve(i+2,j,a);
        int not_take = solve(i+1,j,a);

        return dp[i] =  max(not_take,take);
    }

public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        if(n == 1) return nums[0];

        int mx1 = solve(0,n-2,nums);
        memset(dp,-1,sizeof(dp));
        int mx2 = solve(1,n-1,nums);
        return max(mx1,mx2);
    }
};