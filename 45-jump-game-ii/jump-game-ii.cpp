class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e7);
        dp[0] = 0;

        // for(int i=0;i<n;i++){
        //      for(int j = i + 1;j <= min(n-1,i + nums[i]);j++){
        //         dp[j] = min(dp[j],dp[i]+1);
        //      }
        // }

        // return dp[n-1];
        int curr_end= 0,mx_reach = 0,jump = 0;
      


        for(int i=0;i<n-1;i++){
             
             mx_reach = max(mx_reach,i + nums[i]);

             if(i == curr_end){
                jump++;
                curr_end = mx_reach;
             }
        }
        return jump;
    }
};