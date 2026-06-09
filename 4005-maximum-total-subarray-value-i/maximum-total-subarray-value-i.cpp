class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        #define ll long long 

        ll mn = 1e9,mx = 0;
        for(auto &t : nums){
            ll val = (ll)t;
            mn = min(mn, val);
            mx = max(mx, val);
        }

        return 1LL * (mx - mn)* 1LL * k;
    }
};