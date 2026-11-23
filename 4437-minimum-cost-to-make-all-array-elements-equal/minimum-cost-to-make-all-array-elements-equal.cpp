class Solution {
    #define ll long long 
public:
    long long minCost(vector<int>& nums) {
        
        ll cost = 1e18;
        int n = nums.size();

        int p_mn = nums[0],p_mx  = nums[0];
        vector<int> sfx_mn(n),sfx_mx(n);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                sfx_mn[i] = nums[i];
                 sfx_mx[i] = nums[i];
            }else{
                sfx_mn[i] = min(sfx_mn[i],nums[i]);
                sfx_mx[i] = max(sfx_mx[i],nums[i]);
            }
        }
        for(int i=1;i + 1 < n; i++){
            p_mn = min(p_mn,nums[i]);
            p_mx = max(p_mx,nums[i]);
            int v = nums[i];
            int j = i;
            ll n_cost = -1;
            if(p_mn != p_mx){
               n_cost =  i *1LL*  nums[i];
            }
            if(nums[i] == nums[i+1]){
                j = i+1;
                while(j < n && nums[j] == nums[i]){
                   j++;
                }
                i = j-1;

            }
            if(sfx_mn[i] != sfx_mx[i]){
                if(n_cost == -1)n_cost = 0;
                n_cost += ((n-1-i) * 1LL * nums[i]);
            }
            
            if(n_cost != -1){
                cost = min(cost,n_cost);
            }
        }
        return (cost==1e18) ? 0 : cost;

    }
};