// class Solution {
//     int dp[1001][1001];
//     int valid(string &s,int i,int j){
        
//         if(i >= j){
//             return 1;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         if(s[i] == s[j]){
//             return dp[i][j] = valid(s,i+1,j-1);
//         }else{
//                return 0;
//         }
//     }

// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         memset(dp,-1,sizeof(dp));

//         int mxlen = INT_MIN,sp = 0;

//         for(int i=0;i<n;i++){
//             for(int j = i ; j< n;j++){
//                 if(valid(s,i,j)==1){
//                     if((j - i+1) > mxlen){
//                         mxlen = (j - i+1);
//                         sp = i;
//                     }
//                 }
//             }
//         }

//         return s.substr(sp,mxlen);
//     }
// };



// tabulation ->>>>>>>>>>>>>>..

class Solution {
    int dp[1001][1001];
   
public:
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp,0,sizeof(dp));

        int mxlen = 1,s_idx = 0;
        // handle base case proper;
        for(int i=0;i<=n;i++){
            dp[i][i] = 1;
        }
        for(int l = 2;l <= n;l++){ // for len 1, all single char palindrome
            for(int i=0;i<(n-l+1);i++){
                
                int j =  i + l -1;
                    
                    if(s[i] == s[j] && l==2){
                        dp[i][j] = 1; // true
                        if(j - i + 1 > mxlen){
                            mxlen = j-i+1;
                            s_idx = i;
                        }
                    }else if(s[i] == s[j] && dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        if(j - i + 1 > mxlen){
                            mxlen = j-i+1;
                            s_idx = i;
                        }
                    }else{ 
                        dp[i][j] = 0;
                    }
                
            }
        }
        cout<<mxlen;
        return s.substr(s_idx,mxlen);
    }
};