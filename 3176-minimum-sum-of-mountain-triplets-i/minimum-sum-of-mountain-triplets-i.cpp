class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pfx(n),sfx(n);
        
        for(int i=0;i<n;i++){
            if(!i)pfx[i] = nums[i];
            else pfx[i] = min(pfx[i-1],nums[i]);
        }

         for(int i=n-1;i>=0;i--){
            if(i==n-1)sfx[i] = nums[i];
            else sfx[i] = min(sfx[i+1],nums[i]);
        }

        int mn = 200;
         for(int i=1;i<n-1;i++){
           if(pfx[i-1] < nums[i] && nums[i] > sfx[i+1]){
              mn = min(mn, pfx[i-1]+nums[i]+sfx[i+1]);
           }
        }

        return (mn == 200 ? -1 : mn);
        
        
    }
};