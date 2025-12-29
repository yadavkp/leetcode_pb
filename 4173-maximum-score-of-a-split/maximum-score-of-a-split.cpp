#define ll long long
class Solution {
public:
    long long maximumScore(vector<int>& a) {
        int n = a.size();
       vector<ll> pfx(n),sfx(n); 

       pfx[0] = a[0],sfx[n-1] = a[n-1];

       for(int i=1;i<n;i++){
            pfx[i] = pfx[i-1] + a[i];
       }
       for(int i = n-2;i>=0;i--){
            sfx[i] = min(sfx[i+1],(ll)a[i]);
       }
       ll mx = -1e17;
       for(int i=0;i<n-1;i++){
            mx = max(mx, pfx[i] - sfx[i+1]);
       }

       return mx;
    }
};