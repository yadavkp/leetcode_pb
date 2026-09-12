class Solution {
    #define ll long long 
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        ll L_sum = accumulate(nums.begin(),nums.begin()+n/2,0LL);
        // cout<< sum<<" ";
        ll R_sum = accumulate(nums.begin(),nums.end(),0LL);

        R_sum -= L_sum;

        
      ll tot = L_sum + R_sum;
       
        for(int i =0;i < n/2;i++){
            nums.push_back(nums[i]);
        }

        int cnt = 0;
        for(int i=0;i < n;i++){
            if(L_sum > R_sum)cnt++;

            L_sum -= nums[i];
            L_sum += (nums[i + ((n/2))]);
            R_sum = tot - L_sum;
        }
        return cnt;


    }
};