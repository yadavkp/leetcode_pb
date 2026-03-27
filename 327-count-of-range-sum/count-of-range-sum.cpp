class Solution {
     #define ll long long 
    static const int N = 1e5+5;
    ll seg[4*N];
 
    ll find_query(int idx,int ql,int qr,int l,int r){

        if(r < ql || qr < l) return 0LL;

        if(ql <= l && r <= qr){
            return seg[idx];
        }

       

        int mid = l +(r - l)/2;

      return   find_query(2*idx+1,ql,qr,l,mid)+find_query(2*idx+2,ql,qr,mid+1,r);
        
    }

    void update(int idx,int i,int l,int r){

        if(l == r){
            seg[idx] += 1;
            return;
        }

         int mid = l +(r - l)/2;

         if(i <= mid)update(2*idx+1,i,l,mid);
         else update(2*idx+2,i,mid+1,r);

         seg[idx] = seg[2*idx+1] + seg[2*idx+2];


    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size();
        ll cnt = 0;
        memset(seg,0,sizeof(seg));

        vector<ll> pfx1(n+1,0),pfx;
        for(int i=0;i<n;i++){
            pfx1[i+1] = pfx1[i] + (ll)nums[i];
        }
        pfx = pfx1;
        sort(pfx.begin(),pfx.end());

        pfx.erase(unique(pfx.begin(),pfx.end()),pfx.end());


        for(auto &pj : pfx1){

            ll left = pj - upper;
            ll right = pj - lower;

            auto l_id = lower_bound(pfx.begin(),pfx.end(),left) - pfx.begin();
            auto r_id = upper_bound(pfx.begin(),pfx.end(),right) - pfx.begin()-1;

            if(l_id <= r_id){
                cnt += find_query(0,l_id,r_id,0,n);
            }

            auto id = lower_bound(pfx.begin(),pfx.end(),pj) - pfx.begin();

            update(0,id,0,n);
        }
        return cnt;

    }
};

