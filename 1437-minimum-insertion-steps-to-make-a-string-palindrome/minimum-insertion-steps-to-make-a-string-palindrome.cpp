class Solution {
    //vector<vector<int>> dp;
    int dp[500][500];
    int solve(int i,int j,string &s){

        if(i >= j)return 0;

        if(dp[i][j] != -1)return dp[i][j];
      
        if(s[i] == s[j]){
            return dp[i][j] =  solve(i+1,j-1,s);
        }else{
      
             return dp[i][j] = 1 + min(solve(i,j-1,s),solve(i+1,j,s));
        }
    

    }
public:
    int minInsertions(string s) {
        int n = s.size();
       // dp.assign(n,vector<int>(n,-1));
       memset(dp,-1,sizeof(dp));
        int ans = solve(0,n-1,s);

        return ans;

    }
};