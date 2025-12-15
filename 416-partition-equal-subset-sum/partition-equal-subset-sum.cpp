class Solution {

    vector<vector<int>> dp;
    bool findsum(int idx,int n,vector<int>&a,int sum,int curr){
   
   
        if(curr == sum)return 1;
        if(curr > sum || idx >= n)return 0;
        
        if(dp[idx][curr]  != -1)return dp[idx][curr];
        
     return dp[idx][curr] =  findsum(idx+1,n,a,sum,curr + a[idx]) || findsum(idx+1,n,a,sum,curr);;
        
     
        
    }
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        dp.assign(n,vector<int>(1e4+1,-1));
        int sum = 0;
        for(auto t :  nums)sum += t;
        bool ans = false;
        if(sum%2==0){
            ans = findsum(0,n,nums,sum/2,0);
        }

        return ans;
    }
};