class Solution {
    int cnt = 0;
    unordered_map<string,int> dp;

    int solve(string s){
        if(s.empty()){
            return 1;
        }
        
        if(s[0] == '0'){
           return 0 ;
        }

         if(dp.count(s))return dp[s];

        int ways = 0;
      
        ways += solve(s.substr(1));
        if(s.size() < 2){
           return dp[s] = ways;
        }
         string yes = s.substr(0,2);
        if(yes >= "10" && yes <= "26"){
           ways +=  solve(s.substr(2));
        }

        return dp[s] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        return solve(s);
        //return dp[s];
    }
};