class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
           int val = -1;
           for(int i=1;i<10000;i++){
            if((i | (i+1)) == x){
                val = i;
                break;
            }
           }
           ans.push_back(val);
        }
        return ans;
    }
};