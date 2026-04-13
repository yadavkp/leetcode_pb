class Solution {
public:
    int longestBalanced(string s) {  // ohh , we have to make string rev and also check it may be reverse ans might be the ans
        string rev = s;
        reverse(rev.begin(), rev.end());
        return max(solve(s), solve(rev));
    }

    int solve(const string& s) {
        int n = s.size();
        int zero = 0, one = 0;

        for (char c : s) {
            if (c == '0') zero++;
            else one++;
        }

        if (zero == one) return n;

        unordered_map<int, int> mp;
        mp[0] = -1;  // prefix sum 0 at index -1 (before string starts)

        int ans = 0;
        int prefSum = 0;

        for (int r = 0; r < n; r++) {
            prefSum += (s[r] == '1' ? 1 : -1);

            if (mp.count(prefSum)) {
                ans = max(ans, r - mp[prefSum]);
            }

            if (mp.count(prefSum - 2)) {
                int len = r - mp[prefSum - 2];
                if (len % 2 == 0 && len / 2 <= zero)
                    ans = max(ans, len);
            }

            if (mp.count(prefSum + 2)) {
                int len = r - mp[prefSum + 2];
                if (len % 2 == 0 && len / 2 <= one)
                    ans = max(ans, len);
            }

            if (!mp.count(prefSum)) mp[prefSum] = r;
        }

        return ans;
    }
};