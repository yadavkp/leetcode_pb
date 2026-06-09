class Solution {
public:

    int calc_histogram(vector<int>&nums){
        
        int mx = 0,n = nums.size();
        vector<int> pse(n), nse(n);
        stack<int> stk1;

        for(int i=0;i<n;i++){
            while(!stk1.empty() && nums[stk1.top()] >= nums[i]){
                stk1.pop();
            }
            if(stk1.empty()) pse[i] = -1;
            else pse[i] = stk1.top();

            stk1.push(i);
        }

        while(!stk1.empty()){
            stk1.pop();
        }

        for(int i = n-1;i>=0;i--){
             
              while(!stk1.empty() && nums[stk1.top()] >= nums[i]){
                stk1.pop();
            }
            if(stk1.empty()) nse[i] = n;
            else nse[i] = stk1.top();
            stk1.push(i);
        }

      //  int mx = 0;

        for(int i = 0;i<n;i++){

            int width = nse[i] - pse[i] - 1;
           

            mx = max(mx, nums[i]  * width);

        }
        
        return mx;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n = mat.size(),m = mat[0].size();
        int mx = 0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
           
                for(int j = 0;j<m;j++){
                    if(mat[i][j] == '1'){
                        height[j] += 1;
                    }else{
                        height[j] = 0;
                    }
                }
            
            mx = max(mx,calc_histogram(height));
        }

        return mx;
    }
};