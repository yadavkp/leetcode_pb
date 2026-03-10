class Solution {
    #define ll __int128
public:
    int smallestBalancedIndex(vector<int>& nums) {
        ll n = nums.size();
        
        ll lsum = 0;
        for(ll i=0;i<n;i++){
            lsum += nums[i];
        }
        int idx = -1;
       ll r_pdt = 1;
        for(ll i=n-1;i>=0;i--){
           

            lsum -= nums[i];
            if(lsum == r_pdt){
                idx = i;
            }
            if(r_pdt > lsum / nums[i]) break;

            r_pdt *= nums[i];
        }
        
        return idx;

    }
};