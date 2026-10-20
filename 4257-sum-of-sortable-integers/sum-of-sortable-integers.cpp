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
        
        int mx = 0;
        for(int i=0;i < n;i+=k){
            int cur = nums[i];
            int cur_mx = nums[i];
            int cnt = 0;

            for(int j = i;j < i+ k-1;j++){
                if(nums[j] > nums[(j+1)])cnt++;
                cur = min(cur,nums[j]);
                cur_mx = max(cur_mx,nums[j]);
            }

            if(nums[i + k -1] > nums[i])cnt++;
            cur = min(cur, nums[i + k - 1]);
            cur_mx = max(cur_mx, nums[i + k - 1]);

             if(cnt >1 ) return false;
             if(mx > cur )return false;
            mx = max(mx,cur_mx);
           
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