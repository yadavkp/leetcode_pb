#define ll long long 
class Solution {
public:
    long long countStableSubarrays(vector<int>&a) {
        
        ll ans = 0;
        int n = a.size();
        vector<ll> pfx(n);
        pfx[0] = a[0];

        for(int i=1;i<n;i++){
            pfx[i] = pfx[i-1] + a[i];
        }

        map<pair<ll,ll>,ll> mpp;
        for(int i=0;i<n;i++){
            if(i >= 2){
                ans += mpp[{a[i],pfx[i]}];
            }
            if(i-1 >= 0)mpp[{a[i-1],pfx[i-1] + 2*a[i-1]}]++;
        }
        return ans;
        
    }
};