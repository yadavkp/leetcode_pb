class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        
        int n = nums.size();

        #define ll long long 
        ll ans = 0;
        vector<int> st; // monotic inreasing stack ;
        for(auto x : nums){
            
            while(!st.empty() && st.back() > x){
                st.pop_back();
            }

            auto lb = lower_bound(st.begin(),st.end(),x) - st.begin();

            ans += lb;

            st.push_back(x);
        }

        return ans;
    }
};