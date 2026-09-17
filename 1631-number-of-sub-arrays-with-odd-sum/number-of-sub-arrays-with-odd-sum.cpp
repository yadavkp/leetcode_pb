class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        #define ll long long 
        ll ans = 0;
        ll ev = 1, od = 0,pfx_sum = 0;
        for(int i=0;i < n;i++){

            pfx_sum += (nums[i] % 2);
            if(pfx_sum %2){
                od++;
                ans = (ans  + ev) % mod;
            }else{ 
                ev++;
                ans = (ans + od)% mod;
            }
        }



        return (int)ans;
    }
};