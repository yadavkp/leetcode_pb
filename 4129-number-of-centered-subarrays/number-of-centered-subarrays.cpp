class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        
        int cnt = 0;
        int n = nums.size();

        for(int i = 0;i < n;i++){
             unordered_set<int> seen;
            int sum = 0;
            for(int j = i;j < n;j++){
                seen.insert(nums[j]);
                sum += nums[j];

                if(seen.count(sum)){
                   cnt++;
                }

            }
            
        }

        return cnt;
    }
};