class Solution {
    #define ll long long 

    int solve(vector<int>&nums, ll sum){

        int mx_len = 0,i = 0;
        ll cur = 0;
        int n = nums.size();
        for(int j=0;j < n;j++){

            cur += nums[j];

            while(cur > sum){
                cur -= nums[i];i++;
            }


            if(cur == sum) mx_len = max(mx_len, j - i + 1);

        }

        return mx_len;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        
        // Sliding window based pb, but need to think in the reverse 
        ll sum = 0;
        for(auto t : nums)sum += t;
         int n = nums.size();
        if(sum < x) return -1;
        if(sum == x) return n;
        sum -= x; 
        
        int mx_len = solve(nums,sum) ;

        if(mx_len <= 0) return -1;

        return (n - mx_len);
    }
};