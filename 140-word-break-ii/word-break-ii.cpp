class Solution {
    vector<string> result;
    unordered_set<string> dict;
    int n;

    void backtrack(int i,string& s, string curr) {
        if(i >= n) {
            result.push_back(curr); // remove last space
            return;
        }

        for(int end = i+1; end <= n; end++) {
            string word = s.substr(i, end-i);
            if(dict.count(word)) {
                string new_sent = curr;
                if(!new_sent.empty()) new_sent += " " ;
                backtrack(end,s, new_sent + word);
                
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(), wordDict.end());
        n = s.size();
        backtrack(0, s, "");//
        return result;
    }
};
