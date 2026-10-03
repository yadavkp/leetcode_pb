class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> idx;
          int n = s.size();
        idx.push(-1);
         int len = 0;
        for(int i = 0;i < n;i++){

            if(s[i] == '(')idx.push(i);
            else{
                if(idx.empty())continue;
                if(idx.top()==-1 || s[idx.top()] == ')'){
                    idx.pop();idx.push(i);
                }else{
                     idx.pop();
                     int p = idx.top();
                     len = max(len, i - p);
                }

               
                
            }
        }

        return len;
    }
};