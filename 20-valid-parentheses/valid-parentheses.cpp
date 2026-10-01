class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){stk.push(c);}
            else{
                if(stk.empty()) return false;
                char ch = stk.top();
                if((c == ')' && ch == '(') ||( c == '}' && ch == '{') || ( c == ']' && ch == '[')){stk.pop();}
                else return false;
            }
        }

        return stk.empty();
    }
};