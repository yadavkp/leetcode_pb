class Solution {
public:
    string largestEven(string s) {
        
        int idx = -1;
        for(int i=0;i<s.size();i++){
            if((s[i]-'0') %2 == 0){
                idx = i;
            }
        }

        if(idx==-1)return "";

        return s.substr(0,idx+1);
    }
};