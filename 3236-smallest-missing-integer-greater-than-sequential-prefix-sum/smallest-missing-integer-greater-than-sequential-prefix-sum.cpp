class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        vector<int> pfx = nums;
        
        pfx[0]  = nums[0];

        int mx = 0;
        mx = max(mx, pfx[0]);
        for(int i=1;i < n; i++){
            
            if((nums[i] - nums[i-1]) == 1){
                pfx[i] = pfx[i-1] + nums[i];
                mx = max(mx, pfx[i]);
            }else{
                break;
            }
        }
        

        unordered_set<int> seen;
        seen.insert(nums.begin(),nums.end());

        while(seen.count(mx)){
            mx++;
        }

        return mx;





    }
};