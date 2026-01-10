// class Solution {
//     int n1,n2;
//     vector<vector<int>> dp;

//     int solve(int i,int j,string &s1, string &s2){

//         if(i == s1.size()){
//             int sum  = 0;
//             for(int k = j;k<n2;k++){
//                 sum += (int)s2[k];
//             }
//             return sum;
//         }
//         if(j == n2){
//              int sum  =0;
//             for(int k = i;k<n1;k++){
//                 sum += (int)s1[k];
//             }
//             return sum;
//         }

//         if(dp[i][j] != -1)return dp[i][j];

//         if(s1[i] == s2[j]){
//             return dp[i][j] =  0 + solve(i+1,j+1,s1,s2);
//         }else{
//             return dp[i][j] =  min((int)s1[i] + solve(i+1,j,s1,s2),
//                         (int)s2[j] + solve(i,j+1,s1,s2));
//         }
//     }

// public:
//     int minimumDeleteSum(string s1, string s2) {

//         n1 = s1.size(),n2 = s2.size();

//         dp.assign(n1,vector<int>(n2,-1));
//         return solve(0,0,s1,s2);

//     }
// };


class Solution {
    int n1,n2;
    vector<vector<int>> dp;
public:
    int minimumDeleteSum(string s1, string s2) {

        n1 = s1.size(),n2 = s2.size();

        dp.assign(n1+1,vector<int>(n2+1,0));

        // base case;
        // if j == n2;
        for(int i=n1-1;i>=0;i--){
            dp[i][n2] = dp[i+1][n2] +  int(s1[i]);  // ffrom back to suffix
        }
        // if i == n1;
        for(int i=n2-1;i>=0;i--){
            dp[n1][i] = dp[n1][i+1] +  int(s2[i]);  // ffrom back to suffix
        }
    

        for(int i=n1-1;i>=0;i--){
            for(int j = n2-1;j>=0;j--){
                
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else if(s1[i] != s2[j]){
                    dp[i][j] = min((int)s1[i] + dp[i+1][j],
                                    (int)s2[j] + dp[i][j+1]);
                }
            }
        }

        return dp[0][0];

    }
};