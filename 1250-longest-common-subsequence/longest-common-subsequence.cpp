/* we solve this pb by 
idea->  start looking from thr back in memoization
        start looking from the start in bottom up approach

bottom up approach that is very efficient for this,where we store value if subsequence occuring matches
and return posn of dp[n][m]

if you want to print the subsequence -> start traversing from back and char match
store them 

*/

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int n = text1.size(),m = text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));

//         for(int i=1;i<=n;i++){
//             for(int j = 1;j<=m;j++){
//                 if(text1[i-1] == text2[j-1]){
//                     dp[i][j] = 1+ dp[i-1][j-1];  // diagonally store
//                 }else{
//                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };


// recursion  ->>>>>>>>>>>>>>>

class Solution {
    vector<vector<int>> dp;
    int solve(int i,int j, string &s1,string &s2){

        // base case 
         if(i < 0 || j < 0) return 0;// 0 lenght subseq if any go out of bond

        //checking to krbalo mere bhai 
        if(dp[i][j] != -1)return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + solve(i-1,j-1,s1,s2);
        }else{

            return dp[i][j] =  max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
        }

    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size(),m = text2.size();
        dp.assign(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2);
    }
};