class Solution {

    vector<int> seg;
    int find_query(int idx,int ql,int qr,int l,int r){

        if(r  <ql || qr < l) return 0;

        if(ql <= l && r <= qr)return seg[idx];

       int mid =  l + (r - l)/2;

        return find_query(2*idx+1,ql,qr,l,mid) + find_query(2*idx+2,ql,qr,mid+1,r);
    }

    void update(int idx,int i,int l,int r){

        if(l == r){
            
            seg[idx] += 1;
           
            return ;
        }

        int mid = l+ (r - l)/2;

        if(i <= mid)update(2*idx+1,i,l,mid);
        else update(2*idx+2,i,mid+1,r);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];

    }

public:
    vector<int> countSmaller(vector<int>& nums) {

          
        reverse(nums.begin(),nums.end());
        int n = nums.size();
        seg.assign(4*n,0);
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());

        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){

            auto idx = upper_bound(temp.begin(),temp.end(),nums[i]) - temp.begin()-1;
           // cout<<idx<<" ";

            int cnt = find_query(0,0,idx-1,0,temp.size()-1);
            ans[i] = cnt;
            update(0,idx,0,temp.size()-1);

        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};