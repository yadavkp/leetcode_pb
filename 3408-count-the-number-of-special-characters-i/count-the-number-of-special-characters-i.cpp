class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        vector<int> frq1(26,0),frq2(26,0);

        for(char ch : s){
            if(isupper(ch)){
                frq1[ch-'A']++;
            }
            if(islower(ch)){
                frq2[ch-'a']++;
            }
        }
int cnt = 0;
        for(int i=0;i<26;i++){
            if( min(frq1[i],frq2[i]) > 0) cnt+=1;
            
        }

        return cnt;
    }
};