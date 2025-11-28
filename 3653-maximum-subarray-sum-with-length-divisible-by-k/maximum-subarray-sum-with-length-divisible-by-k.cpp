#define ll long long
class Solution {
   
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll ans = LLONG_MIN;
        int n = nums.size();
        vector<ll> pfx(n+1,0);

        for(int i=0;i<nums.size();i++){
            pfx[i+1] = pfx[i] + nums[i];
        }

        vector<ll> minPfx(k,LLONG_MAX);
        minPfx[0] = 0; // at start at 0, sum =0, and start indexing from 1
        for(int i = 1;i <= nums.size();i++){

            int mod = i%k;
            if(minPfx[mod] != LLONG_MAX){
                ans = max(ans,pfx[i] - minPfx[mod]);
            }

            minPfx[mod] = min(minPfx[mod],pfx[i]);

        }
        return ans;
    }
};