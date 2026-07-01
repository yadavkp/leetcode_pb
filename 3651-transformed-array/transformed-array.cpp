class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i=0;i<n;i++){
           
           int shift = nums[i];

           result[i] = nums[(( i + shift ) % n + n ) % n]; // this handle all +ve,-ve


 
        }

        return result;
    }
};