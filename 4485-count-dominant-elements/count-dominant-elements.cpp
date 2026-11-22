class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        if(n==1) return 1;

        for(int i=0;i<n;i++){

            
            if(i==0 && i+1 < n){
                if(nums[i]>=nums[i+1])cnt++;
            }else if(i == n-1 && i>0 ){
                if(nums[i]>=nums[i-1])cnt++;
            }else if(i+1< n && i-1 >= 0){
                int  avg = nums[i-1] + nums[i+1];
                
                if(nums[i]*2 >= avg)cnt++;
            }

            
        }
        return cnt;
    }
};