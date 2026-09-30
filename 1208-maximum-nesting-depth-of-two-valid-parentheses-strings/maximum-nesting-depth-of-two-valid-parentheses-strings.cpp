class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);

        stack<char> stk1,stk2;

        for(int i=0;i < n;i++){
            char ch = seq[i];
            if(ch == '('){
                if(stk1.size() > stk2.size()){
                    stk2.push(ch);
                    ans[i] = 1;
                }
                else {
                    stk1.push(ch);
                    ans[i] = 0;
                }
            }else{
                if(stk1.size() > stk2.size()){
                    stk1.pop();
                    ans[i] = 0;
                }
                else {
                    stk2.pop();
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
};