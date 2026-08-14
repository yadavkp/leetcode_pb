class Solution {
    int n;

    bool valid(int mx, vector<int>&nums,int k){

        int cnt =1,sum=0;

        for(int i=0;i < n; i++){
            sum += nums[i];
            if(sum > mx){
                sum = nums[i];
                cnt++;
            }
        }

        return cnt <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        
        n = nums.size();

        int low  = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0)+1;

        int ans = low;
        while(low <= high){

                int mid = low + (high - low) / 2;
            if(valid(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
        
    }
};