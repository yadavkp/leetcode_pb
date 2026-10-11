class Solution {
    #define ll long long 
    bool valid(ll tar,ll k,vector<int>&arr){
        ll cost = 0;
        int n = arr.size();
        for(int i=0;i < n;i++){
            if(arr[i] >= tar){
                cost += (arr[i] - tar);
            }
        }
        return (k >= cost);
    }
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> arr(n);
        for(int i=0;i < n; i++){
            arr[i] = abs(nums1[i] - nums2[i]);
        }
        ll k  = k1 + k2;
        sort(arr.rbegin(),arr.rend());
        // first we want avg_value we can make under the limited operation
        ll avg_val = 1e5;
        ll l=0,r = 1e5;
        while(l <= r){
            ll mid = (l + (r - l)/2);
            if(valid(mid,k,arr)){
                avg_val = min(avg_val,mid);
                r =mid-1;
            }else{
                l = mid+1;
            }
        }
        cout<< avg_val;

        for(int i=0;(i <n  && k>0);i++){
            if(arr[i]>avg_val){
                ll spend = (arr[i] - avg_val);
                k -= spend;
                arr[i] -= spend;
            }
            
        }
       for(int i=0;i < n && k>0;i++){
            if((arr[i] == avg_val) && arr[i]>0){
                k--;
                arr[i]-=1;
            }
        }
        ll sum = 0;
        for(int i=n-1;i >=0;i--){
            sum += (arr[i] * 1LL * arr[i]);
        }
        return sum;
    }
};