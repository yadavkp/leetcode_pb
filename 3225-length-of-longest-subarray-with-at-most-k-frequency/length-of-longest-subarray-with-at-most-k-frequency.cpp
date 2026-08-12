class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int len = 0,n = nums.size();
        map<int,int> mp;
        int l = 0;

        for(int r = 0; r  < n; r++ ){

            mp[nums[r]]++;
            while(!mp.empty() && mp[nums[r]] > k){

                mp[nums[l]]--;
                l++;
            }

            len = max(len, r - l + 1);
        }

        return len;
    }
};