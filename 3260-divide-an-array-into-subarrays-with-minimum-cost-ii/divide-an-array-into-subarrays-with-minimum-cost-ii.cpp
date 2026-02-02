
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        multiset<int> low, high;  // low = k-1 smallest
        long long sumLow = 0;

        auto balance = [&]() {
            while ((int)low.size() > k - 1) {
                auto it = prev(low.end());
                high.insert(*it);
                sumLow -= *it;
                low.erase(it);
            }
            while ((int)low.size() < k - 1 && !high.empty()) {
                auto it = high.begin();
                low.insert(*it);
                sumLow += *it;
                high.erase(it);
            }
        };

        auto add = [&](int x) {
            if (low.empty() || x <= *prev(low.end())) {
                low.insert(x);
                sumLow += x;
            } else {
                high.insert(x);
            }
            balance();
        };

        auto remove = [&](int x) {
            if (low.find(x) != low.end()) {
                low.erase(low.find(x));
                sumLow -= x;
            } else {
                high.erase(high.find(x));
            }
            balance();
        };

        int l = 1;
        for (int r = 1; r < n; r++) {
            add(nums[r]);

            while (r - l > dist) {
                remove(nums[l]);
                l++;
            }

            if ((int)low.size() == k - 1) {
                ans = min(ans, nums[0] + sumLow);
            }
        }

        return ans;
    }
};
