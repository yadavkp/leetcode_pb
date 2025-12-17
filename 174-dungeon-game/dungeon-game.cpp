class Solution {
    int n, m;
    vector<vector<int>> dp;
    int path(int r, int c, vector<vector<int>>& dun) {
        if (r >= n || c >= m) return 1e9; // out of bounds

        if (r == n-1 && c == m-1) {
            return max(1, 1 - dun[r][c]); // base case
        }

        if(dp[r][c] != -1)return dp[r][c];

        int down = path(r+1, c, dun);
        int right = path(r, c+1, dun);

        int need = min(down, right) - dun[r][c];
        return dp[r][c] = max(1, need);
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        n = dun.size();
        m = dun[0].size();
        dp.assign(n,vector<int>(m,-1));
        int ans = path(0, 0, dun);
        return ans;
    }
};