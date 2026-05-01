class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();
       
        int sum = 0;
        int fprev = 0;
        for(int i=0;i<n;i++){
           sum += nums[i];
           fprev += (i * nums[i]);
        }
        
        int mx = fprev;
        for(int i=1;i<n;i++){
            fprev += sum - n * nums[n-i]; 
            mx = max(mx,fprev);
        }

        return mx;
    }
};