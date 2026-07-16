class Solution {
    #define ll long long 
    ll sum = 0;
public:
    long long gcdSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pfx_gcd(n);
        int mx = nums[0];

        pfx_gcd[0] = mx;
        for(int i=1;i<n;i++){
            mx = max(mx,nums[i]);
            pfx_gcd[i] = __gcd(mx,nums[i]);
        }
        sort( pfx_gcd.begin(), pfx_gcd.end());

        for(int i=0;i < (int)pfx_gcd.size()/2;i++){

            sum += __gcd(pfx_gcd[i], pfx_gcd[n-1-i]);
        }
        
        return sum;
    }
};