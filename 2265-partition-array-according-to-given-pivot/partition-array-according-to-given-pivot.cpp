class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        // first smaller 
        // then equal 
        // then greater

        for(auto &v : nums){
            if(v < pivot)ans.push_back(v);
        }
        for(auto &v : nums){
            if(v == pivot)ans.push_back(v);
        }
        for(auto &v : nums){
            if(v > pivot)ans.push_back(v);
        }

        return ans;
    }
};