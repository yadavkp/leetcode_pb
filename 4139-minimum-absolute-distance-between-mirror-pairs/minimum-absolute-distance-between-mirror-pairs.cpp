#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse digits of a number (ignoring leading zeros)
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> seen; 
        int ans = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
           
            int target = nums[j];
            if (seen.count(target)) {
                ans = min(ans, j - seen[target]);
            }

          
            int rev = reverseNum(nums[j]);
            seen[rev] = j;
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};