class Solution {
    int mod = 1e9 + 7;
#define ll long long
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();
        vector<ll> non_zero_count(n, 0);
        vector<ll> num_upto(n, 0);
        vector<ll> digit_sum(n, 0);
        vector<ll> pow10(n + 1, 0);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % mod;
        }
        non_zero_count[0] = ((s[0] - '0') != 0) ? 1 : 0;

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            non_zero_count[i] = non_zero_count[i - 1] + ((digit != 0) ? 1 : 0);
        }

        num_upto[0] = (s[0] - '0');
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';

            if (digit != 0)
                num_upto[i] = (num_upto[i - 1] * 10 + digit) % mod;
            else
                num_upto[i] = num_upto[i - 1];
        }

        digit_sum[0] = (s[0] - '0');
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            digit_sum[i] = digit_sum[i - 1] + digit;
        }

        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
           int num_b4 = (l == 0) ? 0 : num_upto[l-1];
            int k = non_zero_count[r] - ((l == 0) ? 0 : non_zero_count[l - 1]);
            ll sum = digit_sum[r] - (l == 0 ? 0 : digit_sum[l - 1]);
           ll x = (num_upto[r] - (num_b4 * pow10[k]) % mod + mod) % mod;

            ans[i] = (x * (sum % mod)) % mod;
        }

        return ans;
    }
};