class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int ans = k+1;
        int n = nums.size();
        int mx = 0;
        vector<int> sfx_mn(n);
        sfx_mn[n-1] = nums[n-1];
        for(int i = n-2;i >= 0;i--){
            sfx_mn[i] = min(nums[i], sfx_mn[i+1]);
        }
    int idx = n+1;
        for(int i = 0;i < n; i++){

            mx = max(mx, nums[i]);
            int mn = mx - sfx_mn[i];
            
            if( mn <= k){
                k = mn;
                idx = min(idx, i);
            }
        }

        if(idx == n+1)idx = -1;

        return idx;

    }
};