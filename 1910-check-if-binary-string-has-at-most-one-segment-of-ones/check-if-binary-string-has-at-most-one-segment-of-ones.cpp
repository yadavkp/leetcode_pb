class Solution {
public:
    bool checkOnesSegment(string s) {
        int  ok = 0;
        for(int i=0;i<s.size();i++){

            if(s[i] == '1' && ok == 1)return false;
            if(s[i] == '1'){
                i++;
                while(i < s.size() && s[i]=='1' ){
                   i++;
                }
                ok  = 1;
            }
        }

        return true;
    }
};