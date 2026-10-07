class Solution {
    int n;
    unordered_set<string> seen;

    void solve(int i, string &s, string &got, int bal, int L, int R) {
        if (bal < 0) return;                    // ')' zyada ho gaye, cut

        if (i == n) {
            if (L == 0 && R == 0 && bal == 0)   // minimum removal + valid
                seen.insert(got);
            return;
        }

        char c = s[i];

        // 1) letter: lena hi hai
        if (c != '(' && c != ')') {
            got.push_back(c);
            solve(i + 1, s, got, bal, L, R);
            got.pop_back();
            return;
        }

        // 2) bracket SKIP: sirf agar budget bacha ho
        if (c == '(' && L > 0) solve(i + 1, s, got, bal, L - 1, R);
        if (c == ')' && R > 0) solve(i + 1, s, got, bal, L, R - 1);

        // 3) bracket TAKE: hamesha allowed
        got.push_back(c);
        solve(i + 1, s, got, bal + (c == '(' ? 1 : -1), L, R);
        got.pop_back();
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        seen.clear();

        // L = kitne '(' hatane, R = kitne ')' hatane
        int L = 0, R = 0;
        for (char c : s) {
            if (c == '(') L++;
            else if (c == ')') {
                if (L > 0) L--;
                else R++;
            }
        }

        string got = "";
        solve(0, s, got, 0, L, R);

        return vector<string>(seen.begin(), seen.end());
    }
};