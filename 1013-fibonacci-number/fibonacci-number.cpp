
class Solution {
     vector<int> dp = vector<int>(40,-1);
       
public:
    int fib(int n) {
      dp[0] = 0;
      dp[1] = 1;
      
      if(n <= 1){
        return n;
      }
      if(dp[n] != -1){
        return dp[n];
      }
      dp[n] =  fib(n-1) + fib(n-2);
      return dp[n]; 
    }
};