#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        int max_val = *max_element(nums.begin(), nums.end()) * 2;

        vector<long long> freqPrev(max_val + 1, 0);
        vector<long long> freqNext(max_val + 1, 0);

        // initialize freqNext with all counts
        for (int x : nums) {
            freqNext[x]++;
        }

        long long ans = 0;
        for (int x : nums) {
            freqNext[x]--;              // remove current from future
            int t = x * 2;
            if (t <= max_val) {
                ans = (ans + freqPrev[t] * freqNext[t]) % MOD;
            }
            freqPrev[x]++;              // add current to prefix
        }

        return (int)ans;
    }
};