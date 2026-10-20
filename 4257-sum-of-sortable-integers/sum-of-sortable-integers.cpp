class Solution {
    int n;

    void find_fact(int n,vector<int>&factor){

        for(int i=1;i*i <= n;i++){
            if((n%i) == 0){
                factor.push_back(i);
                if((n/i) != i)factor.push_back(n/i);
               
            }
        }
    }

    bool valid(int k,vector<int>&nums){
        
        int left_mx = 0;
        for(int i=0;i < n;i+=k){
            int right_mn = nums[i];
            int right_mx = nums[i];
            int cnt = 0;

            for(int j = i;j < i+ k-1;j++){
                if(nums[j] > nums[(j+1)])cnt++;
                right_mn = min(right_mn,nums[j]);
                right_mx = max(right_mx,nums[j]);
            }

            if(nums[i + k -1] > nums[i])cnt++;
            right_mn = min(right_mn, nums[i + k - 1]);
            right_mx = max(right_mx, nums[i + k - 1]);

            if(cnt >1 ) return false; // got descending more than  1,
            if(left_mx > right_mn )return false;

            left_mx = max(left_mx,right_mx);
           
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        n = nums.size();
        vector<int> factor;
        find_fact(n,factor);

        int cost = 0;
        for(auto k : factor){
            if(valid(k,nums)){
                cost += k;
            }
        }

        return cost;
    }
};