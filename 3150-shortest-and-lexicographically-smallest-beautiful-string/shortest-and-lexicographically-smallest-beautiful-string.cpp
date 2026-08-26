class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();
        string ans = "";

        int l = 0, ones = 0;

        for (int r = 0; r < n; r++) {

            if (s[r] == '1')
                ones++;

            while (ones > k) {
                if (s[l] == '1')
                    ones--;
                l++;
            }

            if (ones == k) {

                int start = l;

                // remove useless leading zeros
                while (start <= r && s[start] == '0')
                    start++;

                string cur = s.substr(start, r - start + 1);

                if (ans.empty() ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans))
                {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};