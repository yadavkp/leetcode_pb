class Solution {

    int pali(string&s){

        int val = 0;
        int i = 0,j = s.size()-1;

        while(i <= j){
            char c1 = s[i],c2= s[j];
            val += min(abs(c1 - c2) , 26 - abs(c1-c2));
            i++,j--;
        }

        return val;
    }
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = 1e9;
        int move = 0;
       for(int i=0; i <n; i++){
        string ss = s;
           if(i>0){
                ss = s.substr(i);
                ss += s.substr(0,i);
            
           }
           ans = min(ans, pali(ss)+move++);
       }

        return ans;

    }
};