// class Solution {
//     int n;

//     int solve(int i,int j,vector<int>&a){
//         if(i >= n || j >= n)return 0;

//         int not_take = solve(i+1,j,a);

//         int take = 0;
//         if(a[i] %a[j] == 0){
//             take = 1 + solve(i+1,i,a);
//         }
//         return max(take,not_take);
//     }

// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         vector<int> arr;
//         nums.push_back(0);

//         n = nums.size();
//         nums.insert(nums.begin(),1);
//         int ans = solve(1,0,nums);
//         cout<<ans<<" ";
//         return arr;
//     }
// };



class Solution {
    int n;
    vector<vector<int>> dp;
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.push_back(0);
      
        nums.insert(nums.begin(),1);
        vector<int> ans;
          n = nums.size();
        dp.assign(n+1,vector<int>(n,0));

        for(int i = n-1;i>=1;i--){
            for(int p_idx = n-2;p_idx>=0;p_idx--){
                int not_take = dp[i+1][p_idx];
                int take = 0;
                if(nums[i] %nums[p_idx] == 0){
                    take = 1 + dp[i+1][i];
                }

                dp[i][p_idx] = max(take,not_take);
            }
        }
    
        int i = 1,p = 0; 
        while(i < n){
            //int not_take = dp[i+1][p];
            int take = 0;
            if(nums[i] %nums[p] == 0){
                take = 1 + dp[i+1][i];
            }
            if(dp[i][p] == take && nums[i] % nums[p] == 0){
                ans.push_back(nums[i]);
                p = i;
            }
            i++;
        }
        ans.pop_back();
        return ans;
       
    }
};