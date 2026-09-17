class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int cur = nums[0], mx = nums[0];
        int n = nums.size();
        for(int i=1;i < n;i++){

            cur = max(nums[i], cur + nums[i]);
            mx = max(mx, cur);
           // if(cur < 0)cur = 0;
        }

        return mx;
    }
};