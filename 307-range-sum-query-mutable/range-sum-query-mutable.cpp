class NumArray {
    
    int seg[120095] ;
    int n;
    vector<int> a;
    void build_seg(int idx,int l,int r){

        if(l == r){
            seg[idx]  = a[l];
            return;
        }

        int mid = l + (r - l)/2;

        build_seg(2*idx+1,l,mid);
        build_seg(2*idx+2,mid+1,r);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2]; 
    }

    void seg_update(int idx,int i,int val,int l,int r){

        if(l == r){
            seg[idx] = val;
            return ;
        }

        int mid = l + (r - l)/2;
        if(i <= mid)seg_update(2*idx+1,i,val,l,mid);
        else seg_update(2*idx+2,i,val,mid+1,r);
        
        

        seg[idx] = seg[2*idx+1] + seg[2*idx+2]; 

    }

    int find_query(int idx,int ql,int qr,int l,int r){

        if(qr < l || r < ql) return 0;

        if(ql <= l && r <= qr){
            return seg[idx];
        }

        int mid = l + (r - l) / 2;

      return   find_query(2*idx+1,ql,qr,l,mid) + find_query(2*idx+2,ql,qr,mid+1,r);
    }

public:
    NumArray(vector<int>& nums) {
        memset(seg,0,sizeof(seg));
        a = nums;
         n = nums.size();
        build_seg(0,0,n-1);
    }
    
    void update(int index, int val) {
        seg_update(0,index,val,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return find_query(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */