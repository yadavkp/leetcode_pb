class Solution {

    int dfs(int i,int d,vector<int>&arr,vector<int>&dp){

        if(dp[i] !=-1) return dp[i];

        int best = 1;
         int n = arr.size();
        for(int nxt = i+1; nxt <= min(n-1,i + d);nxt++){
            if(arr[nxt] >= arr[i]) break;

            best = max(best,1 + dfs(nxt,d,arr,dp));
        }

        // left 

         for(int nxt = i-1; nxt >= max(0,i - d);nxt--){
            if(arr[nxt] >= arr[i]) break;

            best = max(best,1 + dfs(nxt,d,arr,dp));
        }
        
        return dp[i] = best;
    }
public:
    int maxJumps(vector<int>& arr, int x) {

        int n = arr.size();
        vector<int> dp(n,-1);
        int ans = 1;
        for(int i=0;i<n;i++){

          ans = max(ans, dfs(i,x,arr,dp));
        }
       return ans;
    }
};