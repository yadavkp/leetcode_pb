class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n1 = s.size(),n2 = goal.size();

        if(n1 != n2) return false;

        if(s == goal) return true;

        // for(int i=1;i<n1;i++){
        //     string ss1 = s.substr(i,n1-i+1) + s.substr(0,i);
        //    if(ss1  == goal) return true;
         
        // } 

        string ss1 = s + s;
           if(ss1.find(goal) != string::npos) return true;

        return false;
    }
};