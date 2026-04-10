class Solution {
    int m,n;
    int dp[101][21][101];
    int solve(int i,int last,int rem,vector<int>& house,vector<vector<int>>& cost){

        if(rem < 0) return 1e9;
        if(i == m){
            if(rem == 0) return 0;
            else return 1e9;
        }

        if(dp[i][last][rem] != -1) return dp[i][last][rem] ;
        int min_khrcha = 1e9;
        if(house[i] != 0){

            int new_rem = (last == house[i]) ? rem : rem-1;
            min_khrcha =  solve(i+1,house[i],new_rem,house,cost);
           
        }else{

             for(int color = 1;color<=n;color++){

                 int new_rem = (last == color) ? rem : rem-1;
                 
                 int res =  solve(i+1,color,new_rem,house,cost);
                 if(res != 1e9){
                   
                    min_khrcha = min(min_khrcha,cost[i][color-1] + res);
                 }
             }
        }

        return dp[i][last][rem]  = min_khrcha;

    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int mm, int nn, int target) {
        m = mm,n = nn;
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,target,houses,cost);

        return (ans >= 1e9) ? -1 : ans;

        
    }
};
