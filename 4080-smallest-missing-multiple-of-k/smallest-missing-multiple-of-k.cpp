class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        int mul = 1;
        int pdt = k;
        while(find(nums.begin(),nums.end(),pdt) != nums.end()){
            pdt = k * mul++;
        }
        return pdt;
    }
};