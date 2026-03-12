class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        map<int,int> mp;
        mp[0]= 1;
        int sum = 0,cnt=0;
        for(int i=0;i<nums.size();i++){

           sum = (sum + nums[i]%k + k)%k;
           cnt += mp[sum];
           //cout<<sum<<" "<<mp[sum]<<"\n";
           mp[sum]++;

        }

        return cnt;
    }
};