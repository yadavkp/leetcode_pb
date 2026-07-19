class Solution {
    #define ll long long
    const int mod = 1e9 + 7;
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        
        int ans = 0;
        int cnt1=0,cnt2=0;
        for(int i=0;i < nums.size(); i++){
            if(nums[i] < a){
                ans = (ans + cnt1 + cnt2) % mod;
            }else if(nums[i] >= a && nums[i] <= b){
                ans = (ans + cnt2)% mod;
                cnt1++;
            }else{
                cnt2++;
            }
        }

        return ans;
    }
};