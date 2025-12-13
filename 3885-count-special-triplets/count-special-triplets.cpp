class Solution {
    const int mod = 1e9+7;
    #define ll long long 
public:
    int specialTriplets(vector<int>& nums) {
        
        unordered_map<ll,int> tot_frq;
        unordered_map<ll,int> frq;
        for(auto t : nums){
            tot_frq[t]++;
        }
        ll ans = 0;
        for(auto curr : nums){
            ll left = frq[2*curr];
            ll right = tot_frq[2*curr] - left;
            frq[curr]++;
            // edge cases 
            if(curr == 0){
                right -= 1;
            }
            ans  =  (ans + left * 1LL* right )%mod;
        }
        
        return ans;
    }
};