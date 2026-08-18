class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(n == k){
             return *max_element(nums.begin(),nums.end());
        }

        vector<int> frq(51,0);
        for(int v : nums)frq[v]++;

        if(k == 1){
            for(int i = 50;i>=0;i--){
                if(frq[i]==1){
                    return i;
                }
            }
            return -1;
        }

        if(nums[0] == nums[n-1]) return -1;
        int ans = -1;
        if(frq[nums[0]]== 1 && frq[nums[n-1]]==1)ans = max(nums[0],nums[n-1]);
        else if( frq[nums[n-1]]==1)ans = nums[n-1];
        else if(frq[nums[0]]==1)ans = nums[0];
        
       return ans;
    }
};