class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(n == k){
             return *max_element(nums.begin(),nums.end());
        }

        if(k == 1){
            
            vector<int> frq(51,0);
            for(int v : nums)frq[v]++;
            for(int i = 50;i>=0;i--){
                if(frq[i]==1){
                    return i;
                }
            }
            return -1;

        }


        int first  = nums[0], last = nums[n-1];

        if(first == last) return -1;

        int mx = 0;
        if(first > last)mx = first;
        else {
            if(last > first){
                mx = last;
                last = first;
            }
        }

        int cnt = 0;
        for(int v : nums){
            if(v == mx)cnt++;
        }

        if(cnt == 1)return mx;
        cnt = 0;
        for(int v : nums){
            if(v == last)cnt++;
        }

        if(cnt == 1)return last;

        return -1;

        
    }
};