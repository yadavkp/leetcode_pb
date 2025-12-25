// this qn we can't solved by the greedy approach ->
// so we need to apply here dp lcs concept so  easily determind
// here it is better to find longest common subsequce and then add both string len 
// and subtract 2*common subseq = that will be the ans


// here we will oslve pb pb lcs tabulation ->>>>>>>>, also solve by recursion +memoiation 
// ans = s1_len + s2_len - 2*common_subseq

class Solution {
public:
    int minDistance(string s1, string s2) {
       // 
    int n = s1.size(), m = s2.size();
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<=n;i++)dp[i][0] = 0; // base case
        for(int j = 0;j <= m;j++)dp[0][j] = 0;

        for(int i=1;i<=n;i++){
            for(int j = 1;j <= m;j++){
                if(s1[i-1] == s2[j-1]){   // convert in 0 based idx
                        dp[i][j] = 1 + dp[i-1][j-1]; // 1 + solve(i-1,j-1,s1,s2)
                } else{
                    // here two matches or  not matchers
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }

            }
        }

        return n + m - 2 * dp[n][m];

    }
};