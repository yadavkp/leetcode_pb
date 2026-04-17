class Solution {
    int n;
    int memo[200];
    bool solve(int i,string&s,unordered_set<string>&dict ){

        if(i >= n)return true;

        if(memo[i] != -1) return memo[i];
        bool ans = false;
        for(int j=i;j<s.size();j++){
           string pfx = s.substr(i,(j - i)+1);
           if(dict.count(pfx) && solve(j+1,s,dict)){
             return  memo[i] = true;
           }
        }

        return memo[i] = false;;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        unordered_set<string> seen ;
        memset(memo,-1,sizeof(memo));
        seen.insert(wordDict.begin(),wordDict.end());

        return solve(0,s,seen);
    }
};