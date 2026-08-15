class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int x_or = 0;
        int all_zero = 0;
        int n = nums.size();
        for(int i=0; i < n; i++){

            if(nums[i] != 0)all_zero = 1;

            x_or  =  x_or ^ nums[i];
        }

        if(x_or != 0) return n;

        if(all_zero == 1) return n-1; // atleast one non_zero number present 

        return 0;
    }
};