class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        
        unordered_map<string,int> str;
        

        int cnt = 0;
        int n = word.size();
        for(int i=0;i<n;i++){
            string s = "";
            for(int j = i;j<n;j++){
                s += word[j];
                str[s]++;
            }
        }

        for(auto ch : patterns){
            if(str.count(ch))cnt++;
        }
        return cnt;
    }
};