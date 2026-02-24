class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        unordered_map<string,int > mp;
        for(auto st : words)mp[st]++;
        int n = words.size();
        vector<int> res;
        int tot_len = words[0].size()* n;
        
        int N = s.size();
        int L = words[0].size();
        for(int i=0;i<= N-tot_len;i++){
            string new_s = s.substr(i,tot_len);

            unordered_map<string,int> temp;
            for(int j = 0;j<new_s.size();j += L){
                string chunk = new_s.substr(j,L);
                temp[chunk]++;
            }
            if(temp == mp){
                res.push_back(i);
            }
        }

        return res;
    }
};