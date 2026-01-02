class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int num = -1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                num = nums[i];
                break;
            }
        }
        return num;
    }
};