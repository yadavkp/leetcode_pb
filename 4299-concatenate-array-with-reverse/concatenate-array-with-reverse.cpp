class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        ans.insert(ans.end(),nums.begin(),nums.end());
        ans.insert(ans.end(),nums.rbegin(),nums.rend());

        return ans;


    }
};