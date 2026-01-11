class Solution {
public:
    int residuePrefixes(string s) {
        
        int n = s.size();
        unordered_set<char> seen;
        int cnt = 0;
        for(int i=0;i<n;i++){
            seen.insert(s[i]);
            if((i+1) %3 == seen.size()){
                cnt++;
            }
        }
        return cnt;
    }
};