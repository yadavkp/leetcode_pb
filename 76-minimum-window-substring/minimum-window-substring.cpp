class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() < t.size()) return "";

        int hash[255] = {0};
        int cnt = 0,s_idx = -1,mx_len = INT_MAX;
        for(char ch : t){
            hash[ch]++;
            cnt++;
        }

        int i=0,j = 0;
        while(j < s.size()){

            if(hash[s[j]] > 0){
                hash[s[j]]--;
                cnt--;
            }else{
                hash[s[j]]--;
            }

            if(cnt ==0){
              
                while(cnt == 0 && i <= j && j < s.size()){

                    if(mx_len > j - i + 1){
                        s_idx = i,mx_len = min(mx_len,j - i + 1);
                    }
                    hash[s[i]]++;
                    if(hash[s[i]] > 0)cnt++;
                    i++;
                }
            }
            j++;
        }

        return (s_idx == -1) ? "" : s.substr(s_idx,mx_len);
    }
};