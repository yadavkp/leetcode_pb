class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int helper(string &s, string &t, int i, int j) {
        // target pura match ho gaya
        if(j == m) return 1;
        // source khatam ho gaya, target bacha hai
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ways = 0;
        // take
        if(s[i] == t[j]) {
            ways += helper(s, t, i+1, j+1);
        }
        // not_take
        ways += helper(s, t, i+1, j);

        return dp[i][j] = ways;
    }

    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        dp.assign(n, vector<int>(m, -1));
        return helper(s, t, 0, 0);
    }
};
