class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int right = accumulate(nums.begin(),nums.end(),0);
        int left = 0;

        for(int i=0;i<nums.size();i++){
            int ans = abs(left - (right - nums[i]));
            left += nums[i];
            right -= nums[i];
            nums[i] = ans;

        }
        return nums;
    }
};