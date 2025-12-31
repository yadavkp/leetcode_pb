// class Solution {

//     int solve(int c_r,int idx,vector<vector<int>>& triangle){
//         int n = triangle.size();

//         if(c_r == n-1){
//             return triangle[c_r][idx];
//         }

//         int sum  = triangle[c_r][idx];
//         int left = solve(c_r+1,idx,triangle);
//         int right = solve(c_r+1,idx+1,triangle);

//         return sum + min(left,right);
//     }
// public:

//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         int n = triangle.size();
//         return solve(0,0,triangle);
//     }
// };



// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         int n = triangle.size();

//         vector<vector<int>> dp(n,vector<int>(n,0));
//         for(int j = 0;j<n;j++){
//             dp[n-1][j] = triangle[n-1][j];
//         }
//         for(int r = n-2;r >=0;r--){
//             int m = triangle[r].size(); // current column size 
//             for(int c = 0;c < m;c++){
//                 int left = dp[r+1][c];
//                 int right = dp[r+1][c+1];
//                 dp[r][c] = triangle[r][c] +min(left,right);
//             }
//         }

//         return dp[0][0];
//     }
// };



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        int mn = 1e9;
        for(int i=1;i<n;i++){
            for(int j = 0;j <= i;j++){
                if(j == 0)triangle[i][j] += triangle[i-1][j];
                else if(j == i)triangle[i][j] += triangle[i-1][j-1];
                else{
                    triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
                }
                cout<<triangle[i][j]<<" ";
                
            }
            cout<<"\n";
        }

        for(int i=0;i<n;i++){
            mn = min(mn,triangle[n-1][i]);
        }
        return mn;
        //return dp[0][0];
    }
};