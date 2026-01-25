class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();  
        sort(nums.begin(),nums.end());
        if(n==1 || k==1){
            return 0;
        }

        int ans = 1000000;
        k--;
        for(int i = 1; i<n;i++){

            if(i >= k){
                ans = min(ans, nums[i] - nums[i-k]);
            }
        }

        return ans;
    }
};