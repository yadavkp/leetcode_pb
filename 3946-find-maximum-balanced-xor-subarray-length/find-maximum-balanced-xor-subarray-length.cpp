class Solution {
public:
    int maxBalancedSubarray(vector<int>& a) {
        int n= a.size(),mx = 0,xr = 0,ev=0,od=0;

        map<pair<int,int>,int> mp;
        
        mp[{0,0}] = -1;
        for(int i=0;i<n;i++){
            xr ^= a[i];
            if(a[i]%2)od++;
            else ev++;
            int diff = od - ev;
            pair<int,int> key = {xr,diff };
            if(mp.count(key)){
                mx = max(mx, i - mp[key]);
            }else{
                mp[key] = i;
            }
        }
        return mx;
    }
};