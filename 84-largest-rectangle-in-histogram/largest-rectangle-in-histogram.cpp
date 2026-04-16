class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        
        int n = ht.size();
        vector<int> pse(n),nse(n);
        stack<int> stk;
        for(int i=0;i<n;i++){

            while(!stk.empty() && ht[stk.top()] >= ht[i]){
                stk.pop();
            }

            if(stk.empty()) pse[i] = -1;
            else pse[i] = stk.top();

            stk.push(i);
        }
        stack<int> stk1;
        for(int i=n-1;i>=0;i--){

            while(!stk1.empty() && ht[stk1.top()] >= ht[i]){
                stk1.pop();
            }

            if(stk1.empty()) nse[i] = n;
            else nse[i] = stk1.top();

            stk1.push(i);
        }

        int res = 0;
        for(int i=0;i<n;i++){

            int width = nse[i] - pse[i] - 1;
            res = max(res, ht[i] * width);
        }

        return res;
    }
};