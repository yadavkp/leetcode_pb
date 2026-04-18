class Solution {
    bool helper(int i,int j,string&s){
        while(i <= j){
            if(s[i] != s[j]){
               return false;
                
            }
            i++,j--;
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        
        int n = s.size();
        int i = 0,j = n-1;
        while(i < j){
            if(s[i] == s[j]){
                i++,j--;
                
            }else{
                
                bool ans = (helper(i+1,j,s));
                ans |= helper(i,j-1,s);
                return ans;
            }
        }
        return true;
    }
};