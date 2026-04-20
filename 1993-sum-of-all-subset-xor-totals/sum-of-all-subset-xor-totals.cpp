class Solution {
public:
    int helper(vector<int>& nums, int idx, int currXor) {
        // Base case: agar array khatam ho gaya
        if(idx == nums.size()) {
            return currXor; // ek subset ka XOR contribute karega
        }

        // Choice 1: take nums[idx]
        int take = helper(nums, idx+1, currXor ^ nums[idx]);

        // Choice 2: not_take nums[idx]
        int not_take = helper(nums, idx+1, currXor);

        return take + not_take;
    }

    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};
