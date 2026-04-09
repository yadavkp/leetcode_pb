class Solution {
    long long memo[51][51][51];
    #define ll long long
    int m,n;

    const int mod  =1e9 + 7;
    int solve(int i,int j,int move){

        if(move < 0) return 0;

        if(i < 0 || i >= m || j < 0 || j >= n )return 1;

        if(memo[i][j][move] != -1) return memo[i][j][move] % mod;

        ll left = solve(i,j-1,move-1)%mod;
        ll right = solve(i,j+1,move-1)%mod;
        ll up = solve(i-1,j,move-1)%mod;
        ll down = solve(i+1,j,move-1)%mod;

        return memo[i][j][move]= (left + right + up + down) % mod;
    }

public:
    int findPaths(int mm, int nn, int maxMove, int startRow, int startColumn) {
        m = mm,n = nn;
        memset(memo,-1,sizeof(memo));
        return solve(startRow,startColumn,maxMove) % mod;
    }
};