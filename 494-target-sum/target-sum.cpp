class Solution {
public:
    int n;
    // Memo: key = (idx, currSum)
    map<pair<int,int>, int> dp;

    int helper(vector<int>& nums, int idx, int currSum, int target) {
        // Base case
        if(idx == n) {
            return (currSum == target) ? 1 : 0;
        }

        pair<int,int> key = {idx, currSum};
        if(dp.find(key) != dp.end()) return dp[key];

        // Choice 1: take as +
        int add = helper(nums, idx+1, currSum + nums[idx], target);

        // Choice 2: take as -
        int subtract = helper(nums, idx+1, currSum - nums[idx], target);

        return dp[key] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        dp.clear();
        return helper(nums, 0, 0, target);
    }
};
