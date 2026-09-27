class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char> st;
        int n = s.size();

        for(char ch : s){
            
            if(ch == ')'){
                string ss = "";
                while(!st.empty() && st.top() != '('){
                    ss += st.top();
                    st.pop();
                }
                st.pop();
                for(int i = 0;i < ss.size();i++){
                    st.push(ss[i]);
                }
            }else{
                st.push(ch);
            }
        }
        string ans;
        while(!st.empty()){
            ans += (st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};