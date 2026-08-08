class Solution {
    #define ll long long
    const static int N = 1e5+1;
    ll seg[4*N];
    int n;

    ll find_query(ll idx,int l,int r,int ql,int qr){

        if(r < ql ||  qr < l) return 0;

        if(ql <= l && r <= qr){
             return seg[idx];
        }

        int mid = l + (r - l)/2;

        ll left = find_query(2*idx+1,l,mid,ql,qr);

        ll right = find_query(2*idx+2,mid+1,r,ql,qr);

         return left + right;

    }

    void update(int idx,int l,int r, int pos){

        if(l == r){
            seg[idx]++;
            return;
        }

        int mid = l + (r - l) / 2;

        if(pos <= mid)update(2*idx+1,l,mid,pos);
        else update(2*idx+2,mid+1,r,pos);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        
        memset(seg,0,sizeof(seg));
        n = nums.size();
        vector<ll> pfx_odd(n+1,0);

        // count of odd
        for(int i=1;i <= n ; i++){
            pfx_odd[i] = pfx_odd[i-1] + (nums[i-1] &1);
        }

        vector<ll> val(n+1);
        for(int i = 0; i <= n; i++){
            val[i] = ((a + b) * 1LL * pfx_odd[i]) -( b *1LL* i);
        }
        vector<ll> compress = val; // coordinate compression 

        sort(compress.begin(),compress.end());

        compress.erase(unique(compress.begin(),compress.end()),compress.end());

        ll ans = 0;
        int sz = compress.size();
        for(int i = 0;  i <= n; i++){

            int odd = pfx_odd[i];

            ll cur_val = (1LL * odd * (a + b)) - (1LL * b * i);
           //  ll cur_val = val[i];

             auto idx = lower_bound(compress.begin(),compress.end(), cur_val)- compress.begin();

            if(0 <= idx){
                 ans += find_query(0,0,sz-1,0,idx);
            }
             update(0,0,sz-1,idx);
        }

        return ans;
    }
};