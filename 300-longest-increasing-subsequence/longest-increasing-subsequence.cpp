class Solution {
    vector<vector<int>> dp;
    int n;
    int f(int i,int p_idx,vector<int>&a){

        if(i >= n)return 0;

       if(dp[i][p_idx] != -1)return dp[i][p_idx];

        int not_take = f(i+1,p_idx,a);
        int take = 0;
        if(a[i] > a[p_idx]){
            take = 1 + f(i+1,i,a);
        }

        return dp[i][p_idx] =  max(take,not_take);

    }

public:
    int lengthOfLIS(vector<int>& nums) {

        nums.insert(nums.begin(),-1e5);
        for(auto t : nums){
            cout<<t<<" ";
        }
          n = nums.size();
        dp.assign(n,vector<int>(n,-1));

        int ans = f(1,0,nums);
      
        

        return ans;
        //return 0;
    }
};