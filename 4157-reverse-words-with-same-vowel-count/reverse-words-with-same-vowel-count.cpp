class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        string word;
        ss >> word;
        int cnt = 0;
        for(auto &ch  : word){
            if(ch =='a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u')cnt++;
        }

        string ans = word;
        while(ss >> word){
            ans += " ";

            int cnt2 = 0;
            for(auto &ch  : word){
              if(ch =='a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u')cnt2++;
            }
            if(cnt == cnt2){
                reverse(word.begin(),word.end());
            }
            ans += word;
        }

        return ans;

    }
};