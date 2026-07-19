class Solution {
public:
    int minCost(string src, string tar, vector<vector<string>>& rules, vector<int>& cost) {
        
        int n = src.size();
        vector<int> dp(n+2,1e9);

        if(src == tar) return 0;
        dp[0] = 0; // empty string having the cost 0
        for(int i=0;i<n;i++){

            if(dp[i] == 1e9) continue;

            if(src[i] == tar[i]) dp[i+1] = min(dp[i+1], dp[i]);

                for(int j = 0;j < rules.size(); j++){
                    string pat = rules[j][0];
                    string rep = rules[j][1];
                    int len = pat.size();
                    if(i + len <=  n){
                        bool got = true;
                        string giv = src.substr(i,len);
                        
                        int cnt_char = 0;
                        for(int k = 0; k < len;k++){
                            if(pat[k] == '*'){
                                cnt_char++;
                                continue;
                            }
                            if(pat[k] != giv[k]){
                                got = false;
                                break;
                            }
                        }

                        if(got){
                             string target = tar.substr(i,len);
                             if(target == rep){
                                dp[i + len] = min(dp[i+len], dp[i] + cost[j] + cnt_char);
                             }
                        }
                    }
                   
                }
            
        }

        return (dp[n] == 1e9) ? -1 : dp[n];
        
    }
};