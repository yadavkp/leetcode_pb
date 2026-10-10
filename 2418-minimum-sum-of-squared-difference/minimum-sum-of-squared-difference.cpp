class Solution {
    #define ll long long 

    bool valid(ll tar,ll k,vector<int>&arr){
        //if(k <= 0) return false;

        int n = arr.size();
        ll cost = 0;
        for(int i=0;i < n;i++){

            if(arr[i] >  tar){
                cost += (arr[i] - tar );
            }
        }
        return k >= cost;
    }
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> arr(n);
        for(int i =0;i < n;i++){
            arr[i] = abs(nums1[i] - nums2[i]);
           
        }
    

        ll k = k1 + k2;
        sort(arr.begin(),arr.end());

        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        if(sum <= k) return 0;

        ll l = 0,r = 1e5;
        ll ans = 1e18;
        while(l <= r){
            ll mid = (l + (r - l )/2);

            if(valid(mid,k,arr)){
                ans = min(ans,mid);
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
       /// cout<< ans <<" \n";

         sum = 0;
        for(ll i=n-1;i >= 0;i--){
             if(arr[i] > ans){
                ll spend = (arr[i]-ans);
                if(spend <= k){
                    k-= spend;
                    arr[i]-=spend;
                }else{
                    arr[i] -= k;
                    k=0;
                }
                
            }
        }

        for(ll i=n-1;i >= 0 && k > 0;i--){
             
             if(arr[i] == ans && arr[i] > 0){
                 arr[i]--;
                 k--;
             }
            
        }
        for(ll i=n-1;i >= 0;i--){
             
            sum += (arr[i] * 1LL * arr[i] );
            
        }


        return sum;


    }
};