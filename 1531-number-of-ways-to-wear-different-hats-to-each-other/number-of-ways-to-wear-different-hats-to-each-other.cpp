class Solution {
    int dp[41][1<<11];
    const int mod = 1e9 + 7;
    vector<vector<int>> hat_idx;
    int n;
    int solve(int hat,int mask){

        if(mask == (1 << n)-1) return 1;

        if(hat > 40) return 0;
      if(dp[hat][mask] != -1) return dp[hat][mask];
        int ways = 0;
        ways += solve(hat+1,mask);
        ways %= mod;

        for(int person : hat_idx[hat]){

            if(!(mask & 1 << person)){
                ways += (solve(hat+1,mask | 1<<person));
                ways %= mod;
            }
        }

       return  dp[hat][mask] = ways;
    }
public:
    int numberWays(vector<vector<int>>& hats) {
        

          hat_idx.assign(41,{});
        for(int i=0;i<hats.size();i++){
            for(auto t : hats[i]){
                hat_idx[t].push_back(i);
            }
        }

      

        n = hats.size();
        memset(dp,-1,sizeof(dp));

        return solve(1,0);
    }
};