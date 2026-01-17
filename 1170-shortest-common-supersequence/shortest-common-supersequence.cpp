
// this method, first find lcs, then add remaining char in strnig ans, then reverse
// 2nd method was-> if u find the len -> m + n - lcs;
class Solution {
    int n1,n2;
    vector<vector<int>> dp;

public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        n1 = s1.size(),n2 = s2.size();
        dp.assign(n1+1,vector<int>(n2+1,0) );
        
       for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
       }

        string ans;

        int i = n1,j = n2;
        while(i > 0 && j > 0){

            if(s1[i-1] == s2[j-1]){
                ans += s1[i-1];
                i--,j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                ans += s1[i-1];
                i--;
            }else{
                ans += s2[j-1];
                j--;
            }
        }
        
        // add remaining character

        while(i > 0) ans += s1[i-1],i--;
        while(j > 0) ans += s2[j-1],j--;
        reverse(ans.begin(),ans.end());

        return ans;
          
    }
};



// thsi code would give mle, so we have not learn  that



// class Solution {
//     int n1,n2;
//     vector<vector<string>> dp;


//     string f(int i,int j, string &s1,string &s2){

//         if(i == n1) return s2.substr(j,n2-j);

//         if(j == n2) return s1.substr(i,n1-i);

//         if(dp[i][j] != "")return dp[i][j];

//         if(s1[i] == s2[j]){

//             return dp[i][j] =  s1[i]  + f(i+1,j+1,s1,s2);

//         }else{

//             string first = s1[i] + f(i+1,j,s1,s2);
//             string second = s2[j] + f(i,j+1,s1,s2);

//             return dp[i][j] =  (first.size() <= second.size() ? first : second);
//         }

//     }

// public:
//     string shortestCommonSupersequence(string s1, string s2) {
        
//         n1 = s1.size(),n2 = s2.size();
//         dp.assign(n1,vector<string>(n2,"") );
//         string ans = f(0,0,s1,s2);
//         //cout<<ans.size();
//         return ans;
//     }
// };
