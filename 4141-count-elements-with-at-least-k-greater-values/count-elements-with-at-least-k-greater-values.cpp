class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            
            int up = upper_bound(nums.begin(),nums.end(),nums[i]) - nums.begin();

            if(n - up >= k){
                cnt++;
            }
        }
        return cnt;
    }
};