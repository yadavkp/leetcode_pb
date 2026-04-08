class Solution {


    int dp[51][51][51][51];
    int n;
    bool is_out_of_bond(int r1,int c1,int r2,int c2,vector<vector<int>>& grid ){

        if(r1>= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return true;

        return false;
    }
    int solve(int r1,int c1,int r2,int c2,vector<vector<int>>& grid){

        if(is_out_of_bond(r1,c1,r2,c2,grid)) return -1e9;


        if(r1 == n-1 && c1 == n-1)return grid[r1][c1]; // you reached to the end  cell// if single person reachd it means other also reached

        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];

        int cherry = 0;
        if(r1 == r2 && c1 == c2)cherry = grid[r1][c1];
        else cherry = grid[r1][c1] + grid[r2][c2];

        // condn should be followed that both person should move 1 step at a time

        int f1 = solve(r1+1,c1,r2+1,c2,grid);// d//d
        int f2 = solve(r1,c1+1,r2,c2+1,grid); //r //r
        int f3 = solve(r1+1,c1,r2,c2+1,grid); //d//r
        int f4 = solve(r1,c1+1,r2+1,c2,grid); //r//d

        if(max({f1,f2,f3,f4}) == -1e9) return dp[r1][c1][r2][c2] = -1e9;
        return dp[r1][c1][r2][c2] = cherry + max({f1,f2,f3,f4});


    }
public:
    int cherryPickup(vector<vector<int>>& grid) {

        n = grid.size();
        memset(dp,-1,sizeof(dp));
        int ans= solve(0,0,0,0,grid) ;
        return (ans == -1e9 ? 0 : ans);

    }
};