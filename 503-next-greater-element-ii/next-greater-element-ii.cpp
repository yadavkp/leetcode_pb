class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        
        stack<int> stk;
        for(int i=0;i<2*n;i++){
            
            while(!stk.empty() && nums[stk.top()] < nums[i%n]){
                ans[stk.top()] = nums[i%n];
                stk.pop();
            }

            stk.push(i%n);

          

        }

        return ans;
    }
};