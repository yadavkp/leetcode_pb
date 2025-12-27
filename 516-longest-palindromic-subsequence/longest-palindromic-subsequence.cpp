// class Solution {
//     int n;
//     int solve(int i,int j,string &s){

//         if(i > j)return 0;
//         if(i == j)return 1;
//         int match = 0,not_match = 0;
//         if(s[i] == s[j]){
//             match = 2 + solve(i+1,j-1,s);
//         }else{
//             not_match = max(solve(i,j-1,s),solve(i+1,j,s));
//         }

//         return  max(match,not_match);
//     }
// public:
//     int longestPalindromeSubseq(string s) {
//         n = s.size();
//         return solve(0,n-1,s);

//     }
// };


// memoisation
class Solution {
    int n;
    vector<vector<int>> dp;
    int solve(int i,int j,string &s){

        if(i > j)return 0;
        if(i == j)return dp[i][j] = 1;
        int match = 0,not_match = 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s[j]){
            match  = dp[i][j] = 2 + solve(i+1,j-1,s);
        }else{
            not_match = dp[i][j] = max(solve(i,j-1,s),solve(i+1,j,s));
        }

        return  max(match,not_match);
    }
public:
    int longestPalindromeSubseq(string s) {
        n = s.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,s);

    }
};