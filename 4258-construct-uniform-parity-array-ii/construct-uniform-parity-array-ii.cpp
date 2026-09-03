class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn_odd;
        int mn_even = mn_odd =  INT_MAX;

        for(auto x : nums1){

            if(x%2)mn_odd  = min(mn_odd,x);
            else mn_even = min(mn_even,x);
        }

        if(mn_even == INT_MAX || mn_odd == INT_MAX ) return true;

        return mn_odd < mn_even;
    }
};