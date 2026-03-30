class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        string s ="";
        string ss  ="";

        for(int i=0;i<s1.size();i++){
            s += s1[i];
            ss += s2[i];
            i++;
        }
        sort(s.begin(),s.end());
        sort(ss.begin(),ss.end());

        if(s != ss) return false;
  
        s.clear();ss.clear();
        for(int i=1;i<s1.size();i++){
            s += s1[i];
            ss += s2[i];
            i++;
        }

        sort(s.begin(),s.end());
        sort(ss.begin(),ss.end());
       
        if(s != ss) return false;

        return true;


    }
};