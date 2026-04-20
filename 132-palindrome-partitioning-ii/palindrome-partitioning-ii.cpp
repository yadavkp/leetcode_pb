class Solution {
public:
    int n;
    string s;
    vector<int> dp; // dp[i] = min cuts needed for substring s[i..end]

    bool isPalindrome(int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    int helper(int i) {
        // Base case: agar end tak pahunch gaye
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        // Try all possible cuts from i..j
        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j)) {
                // agar s[i..j] palindrome hai, toh cut lagao
                if(j == n-1) {
                    ans = 0; // last substring palindrome hai, no cut needed
                } else {
                    ans = min(ans, 1 + helper(j+1));
                }
            }
        }

        return dp[i] = ans;
    }

    int minCut(string str) {
        s = str;
        n = s.size();
        dp.assign(n, -1);
        return helper(0);
    }
};
