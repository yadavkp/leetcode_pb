class Solution {
    #define ll long long
    const int N = 1e5+1;
    ll dp[100001][4][4];
    int n;
    ll solve(int i,int l,int r,vector<vector<int>>& cost){


        if(i >= n/2) return 0;

        if(dp[i][l][r] != -1) return dp[i][l][r];
        ll min_ans = 1e18;
        for(int c1 = 0;c1<3;c1++){
            for(int c2 = 0;c2 < 3;c2++){

                if(c1 == c2)continue;
                if(c1 == l)continue;
                if(c2 == r)continue;

                ll c_val = (ll)(cost[i][c1] + cost[n-i-1][c2]);
                ll res = solve(i+1,c1,c2,cost);
                min_ans = min(min_ans, c_val + res);
            }
        }
            
            
        return dp[i][l][r] =  min_ans;
    }
public:
    long long minCost(int nn, vector<vector<int>>& cost) {
         n  = nn;
        memset(dp,-1,sizeof(dp));

        return solve(0,3,3,cost);
    }
};