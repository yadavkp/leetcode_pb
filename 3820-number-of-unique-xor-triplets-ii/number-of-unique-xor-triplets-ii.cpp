class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> ans,ans1;

        int n = nums.size();

        for(int i=0;i< n; i++){
            for(int j = i; j < n; j++){
                int val = nums[i] ^ nums[j]; 
                ans.insert(val);
               
            }
        }

        for(int i=0;i< n; i++){
            for(auto v : ans){
                int val = (nums[i] ^ v) ;
                ans1.insert(val);
               
            }
        }

        return ans1.size();
    }
};