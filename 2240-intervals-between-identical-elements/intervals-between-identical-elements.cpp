class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
         #define ll long long
        int n = nums.size();

        vector<ll> ans(n, 0);

        // prefix pass
        unordered_map<int, pair<ll,ll>> mp1; // {count, sum of indices}
        for (int i = 0; i < n; i++) {
            auto &p = mp1[nums[i]];
            ll cnt = p.first, sum = p.second;
            ans[i] += (ll)i * cnt - sum;
            p.first++;
            p.second += i;
        }

        // suffix pass
        mp1.clear();
        for (int i = n-1; i >= 0; i--) {
            auto &p = mp1[nums[i]];
            ll cnt = p.first, sum = p.second;  
            // here we interpert , right to left idx, by subtract n-1,in i indx;
            // so now this work , like we iterate from left to right
            // so sfx, formual can work well 
             ans[i] += (ll)(n-1-i) * cnt - sum;
            p.first++;
            p.second += (n-1-i);
        }

        return ans;
    }
};