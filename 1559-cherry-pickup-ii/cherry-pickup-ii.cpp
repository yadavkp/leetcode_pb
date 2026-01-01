// class Solution {

//     int solve(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid){

//         // bc->
//         if(i < 0 || i >= r || j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)return -1e8;

//         if(i == r-1){
//             if(j1 ==  j2 )return grid[i][j1];
//             else return grid[i][j1] + grid[i][j2];
//         } 

//         int mx = -1e8;
//         // explore path there
//         for(int dj1 = -1;dj1 <= 1; dj1++){
//             for(int dj2 = -1; dj2 <= 1;dj2++){

//                 int value = 0;
//                 if(j1 == j2) value = grid[i][j1];
//                 else value = grid[i][j1] + grid[i][j2];
//                 value += solve(i+1,j1+dj1,j2+dj2,r,c,grid); // call for next 

//                 mx = max(mx,value);
//             }
//         }

//         return mx;
//     }

// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size(),m = grid[0].size();

//         return solve(0,0,m-1,n,m,grid);
//     }
// };



/// memoisatin ->>>>>>>>>>>
class Solution {
    
    vector<vector<vector<int>>> dp;
    int solve(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid){

        // bc->
        if(i < 0 || i >= r || j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)return -1e8;

        if(i == r-1){
            if(j1 ==  j2 )return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        } 

        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        int mx = -1e8;
        // explore path there
        for(int dj1 = -1;dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1;dj2++){

                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += solve(i+1,j1+dj1,j2+dj2,r,c,grid); // call for next 

                mx = max(mx,value);
            }
        }

        return dp[i][j1][j2] =  mx;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,grid);
    }
};