class Solution {
    #define ll long long
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = 0;
        for(int i=0;i<nums.size();i++){
           mx = max(mx, nums[i]);
        }

        vector<int> frq(mx+1,0);
        
        for(int i=0;i<nums.size();i++){
            frq[nums[i]]++;
        }

        vector<ll> frq_gcd(mx+1,0);
        for(int g = mx;g >= 1;g--){
                ll cnt = 0;
                    for(ll mul = g; mul <= mx; mul += g){
                        cnt += frq[mul];
                    }

                    ll tot_pair = cnt * (cnt-1 )/2;   // inclusion principe 

                    for(ll pair = g*2; pair <= mx; pair += g){
                        tot_pair -= frq_gcd[pair];      // exclusiion principle 
                    }

                    frq_gcd[g] = tot_pair;
        }

        vector<ll> pfx(mx+1,0);
        int i=0;
        for(int i=1;i<=mx;i++){
           pfx[i] = pfx[i-1] + frq_gcd[i]; 
        }

        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            auto idx = lower_bound(pfx.begin(),pfx.end(),queries[i]+1) - pfx.begin();
            ans[i] = idx;
        }

        return ans;

    }
};