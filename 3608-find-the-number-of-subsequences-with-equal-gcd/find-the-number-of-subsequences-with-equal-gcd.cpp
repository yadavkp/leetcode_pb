class Solution {
    int dp[201][201][201];
    #define ll long long 
    const int mod = 1e9 + 7;
    ll solve(int idx,int g1,int g2,vector<int>&nums){

        if(idx == nums.size()){
            if(g1 == g2 && g1 != 0) return 1;
        
            return 0;
        }

        if(dp[idx][g1][g2] != -1){
            return dp[idx][g1][g2];
        }
        ll ans = 0;
        // not take
        ans += solve(idx+1,g1,g2,nums);

        // in seq 1

        ans += solve(idx+1,__gcd(g1,nums[idx]),g2,nums);


        // in seq 2

        ans += solve(idx+1,g1,__gcd(g2,nums[idx]),nums);

        return dp[idx][g1][g2] = ans % mod;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));

       return solve(0,0,0,nums);
       
    }
};