
// // inside a class you can't initialize directly initializer
// class Solution {
//      //vector<int> dp = vector<int>(40,-1);
//      // this is another method intialize and passing parameter and make constructor
//       vector<int> dp; // ->  that means u make a dp funciton that store two parameter
//      // // now call constructor
    
       
// public:
//     Solution()  : dp(40,-1){
//         dp[0] = 0;
//         dp[1] = 1;
//      }
//     int fib(int n) {
      
//       if(n <= 1){
//         return n;
//       }
//       if(dp[n] != -1){
//         return dp[n];
//       }
//       dp[n] =  fib(n-1) + fib(n-2);
//       return dp[n]; 
//     }
// };


// ->>>>>>>>>>>>>>>>>>>>>>> bottom up approach ->

class Solution {
 
public:
   
    int fib(int n) {
      vector<int> dp(40,-1);
      dp[0] = 0,dp[1] = 1;
     for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
     }
      return dp[n]; 
    }
};