
int cnt;
int n;
class Solution {

    void helper(int i,int j, string&s){

        while( i >= 0 && j < n && s[i] == s[j]){
            cnt++;
           
            i--,j++;
            
        }
    }

public:
    int countSubstrings(string s) {
         n = s.size();

        cnt = 0;
        for(int i = 0; i < n; i++){
            
            helper(i,i,s);
            helper(i,i+1,s);
        }
        return cnt;
    }
};