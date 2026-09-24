class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int idx = -1;

        int n = nums.size();

        for(int i=0;i < n;i++){

            int val = nums[i];
            int sum = 0;
            while(val > 0){
                sum += (val %10);
                val /= 10;
            }
            if(sum == i){
                idx = i;
                break;
            }
        }

        return idx;
    }
};