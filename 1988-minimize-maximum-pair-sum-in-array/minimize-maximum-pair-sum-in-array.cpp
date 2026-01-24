class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size(),mx = 0, i=0,j = n-1;
        while(i < j){
            mx = max(mx,nums[i] + nums[j]);
            i++,j--;
        }

        return mx;
    }
};