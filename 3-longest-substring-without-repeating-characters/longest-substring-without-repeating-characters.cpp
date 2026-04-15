class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = 0;
        int left = 0;
        map<char,int> seen;
        for(int right = 0;right<s.size();right++){
            
             if(seen.count(s[right]) && seen[s[right]] >= left){
                // update pointer;
                left = seen[s[right]] + 1; //extended left poiinter
            }

            len = max(len,right - left + 1);
            seen[s[right]] = right; 
           
        }

        return len;
    }
};