
// recursion  ->>>>>>>>>>>>>>>
// + memoisaton  -> >>>>>>>>>>>
// class Solution {
//     vector<vector<int>> dp;
//     int solve(int i,int j, string &s1,string &s2){

//         // base case 
//          if(i < 0 || j < 0) return 0;// 0 lenght subseq if any go out of bond

//         //checking to krbalo mere bhai 
//         if(dp[i][j] != -1)return dp[i][j];

//         if(s1[i] == s2[j]){
//             return dp[i][j] =  1 + solve(i-1,j-1,s1,s2);
//         }else{

//             return dp[i][j] =  max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
//         }

//     }

// public:
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int n = text1.size(),m = text2.size();
//         dp.assign(n,vector<int>(m,-1));
//         return solve(n-1,m-1,text1,text2);
//     }
// };


// tabulation -.>>>>>>>>>>>>>

// class Solution {
//     vector<vector<int>> dp;
// public:
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int n = text1.size(),m = text2.size();
//         dp.assign(n+1,vector<int>(m+1,-1));
        
//         // base case // if in declaration of dp, we pass 0, that automatic handle base case;, no need to write again base cases;

//         for(int i=0;i<=n;i++)dp[i][0] = 0;
//         for(int j = 0; j<= m;j++)dp[0][j] = 0;

//         for(int i=1;i<=n;i++){
//             for(int j = 1;j<=m;j++){
//                 if(text1[i-1] == text2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];   /// diag fill the data
//                 }else{
//                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]); // other take max of left,top
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };




class Solution {
    int n1,n2;
    vector<vector<int>> dp;

    int solve(int i,int j,string&s1,string&s2){

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + solve(i-1,j-1,s1,s2);
        }else{
            return dp[i][j] =  max(solve(i-1,j,s1,s2), solve(i,j-1,s1,s2));
        }
    }

public:
   int longestCommonSubsequence(string s1, string s2) {
        
        n1 = s1.size(),n2 = s2.size();
        dp.assign(n1+1,vector<int>(n2+1,-1) );
        
        int len = solve(n1-1,n2-1,s1,s2);
    
      return len;
 
    }
};