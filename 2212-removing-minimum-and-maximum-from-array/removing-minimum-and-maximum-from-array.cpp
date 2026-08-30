class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        auto i1 = max_element(nums.begin(),nums.end())-nums.begin();
        auto i2 = min_element(nums.begin(),nums.end()) - nums.begin();

        int n = nums.size();
        if(i2 < i1)swap(i1,i2);

        return min({min(i2+1,n - i1),i1+1 + (n - i2)});

    }
};