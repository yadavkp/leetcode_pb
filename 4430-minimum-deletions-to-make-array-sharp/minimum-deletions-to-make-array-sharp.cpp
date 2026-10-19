class Solution {
public:
    int minDeletions(vector<int>& nums) {

        int n = nums.size();

        int cnt = 0;
        for(int i=1;i < n;i++){
            if(nums[i-1] == nums[i])cnt++;
        }
        
        return cnt;
    }
};