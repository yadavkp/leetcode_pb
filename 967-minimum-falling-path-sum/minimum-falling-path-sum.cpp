class Solution {
    int memo[101][101];
    int solve(int r,int c,vector<vector<int>>& matrix){
        int  n = matrix.size();

        if(c < 0 || c >= n || r >= n)return 1000000000;

        if(r == n-1 && c < n){
            return matrix[r][c];
        }

      if(memo[r][c] != -1e9) return memo[r][c];

        int left = solve(r+1,c-1,matrix);
        int mid = solve(r+1,c,matrix);
        int right = solve(r+1,c+1,matrix);

        return memo[r][c] = matrix[r][c] +   min({left,mid,right});

    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int r = 0;r < n;r++){
            for(int c = 0;c < n;c++){
                memo[r][c] = -(int)1e9;
            }
        }

        for(int c=0;c<n;c++){
            ans = min(ans,solve(0,c,matrix));
        }
        return ans;
    }
};