class Solution {
    int n,mn_pft;
    const int mod = 1e9+7;
   int dp[102][102][102];

    int solve(int i,int pft,int log,vector<int>&group,vector<int>&profit){

        if(i >= group.size()){
            if(pft >= mn_pft && n >= log) return 1;
            return 0;
        }

        if(dp[i][pft][log] != -1) return (dp[i][pft][log]) % mod ;

        int ans = solve(i+1,pft,log ,group,profit);

        if(log + group[i] <= n){
            int next_pft = min(mn_pft,pft + profit[i]);
            ans = (ans + solve(i+1,next_pft,log + group[i],group,profit))%mod;
        }
       // int take = solve(i+1,pft + profit[i],log + group[i],group,profit);


        return dp[i][pft][log]= ans % mod;
        
    }
public:
    int profitableSchemes(int tot, int pft, vector<int>& group, vector<int>& profit) {
        n = tot;
        mn_pft = pft;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,group,profit);
    }
};