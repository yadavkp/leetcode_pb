class Solution {

    int solve(int c_r,int idx,vector<vector<int>>& triangle){

        int n = triangle.size();

        if(c_r == n-1){
            return triangle[c_r][idx];
        }

        int sum  = triangle[c_r][idx];
        int left = solve(c_r+1,idx,triangle);
        int right = solve(c_r+1,idx+1,triangle);

        return sum + min(left,right);
    }
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        //return solve(0,0,triangle);
        // if(n < =1){
        //     return 
        // }
        for(int r = n-2;r >=0;r--){
            int m = triangle[r].size();
            for(int c = 0;c < m;c++){
                triangle[r][c] += min(triangle[r+1][c],triangle[r+1][c+1]);
            }
        }
        return triangle[0][0];
    }
};