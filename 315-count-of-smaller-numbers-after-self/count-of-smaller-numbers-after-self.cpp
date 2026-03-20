//policy based data structures (pbds)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//for duplicates allow use less_equal<T>

// s.find_by_order(k) → iterator to k-th element (0-indexed)
// s.order_of_key(x) → count of elements strictly smaller than x


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ordered_set<int> seen;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            if(seen.empty()){
                ans[i] = 0;
            }else{
                auto it = seen.order_of_key(nums[i]);
                ans[i] = it;
            }

            seen.insert(nums[i]);
        }

        return ans;
    }
};