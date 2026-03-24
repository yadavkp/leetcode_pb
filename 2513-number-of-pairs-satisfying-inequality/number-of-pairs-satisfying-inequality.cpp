class Solution {
    vector<int> seg;
    #define ll long long
    int find_query(int idx,int ql,int qr,int l,int r){


        if(r < ql || qr < l) return 0;

        if(ql <= l && r <= qr) return seg[idx];

        int mid = l + (r - l)/2;

       return  find_query(2*idx+1,ql,qr,l,mid) + 
        find_query(2*idx+2,ql,qr,mid+1,r);
        
    }

    void update(int idx,int n_idx,int l,int r){

            if(l == r){
                seg[idx]++;
                return;
            }

        int mid = l + (r - l)/2;

        if(n_idx <= mid)update(2*idx+1,n_idx,l,mid);
        else update(2*idx+2,n_idx,mid+1,r);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        int n = nums1.size();
        vector<int> A(n);
        for(int i=0;i<n;i++){
            A[i] = nums1[i]-nums2[i];
        }

        // A = n1i-n2i <= n1j-n2j + diff;

    // apply here the coordinate compression 
        vector<int> temp = A;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());

        seg.assign(4*temp.size(),0);


       ll cnt = 0;
        for(int j = 0;j<n;j++){

            ll tar = (ll)A[j] + diff;
            // we are looki
            int lw = upper_bound(temp.begin(),temp.end(),tar) - temp.begin() - 1;
            if(lw >= 0)cnt += find_query(0,0,lw,0,temp.size()-1);
            

            tar = (ll)A[j];
            lw = lower_bound(temp.begin(),temp.end(),tar) - temp.begin();
            update(0,lw,0,temp.size()-1);


        }
        return cnt;
    }
};