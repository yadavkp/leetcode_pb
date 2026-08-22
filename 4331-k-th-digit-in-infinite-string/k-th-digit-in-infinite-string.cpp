class Solution {
    #define ll long long
public:
    int kthDigit(long long k) {
        
        if (k <= 9) return k;
        k--; // 0-based indexing

        vector<ll> pfx(19, 0);
        pfx[1] = 9;
        ll cnt = 90; 

        for (ll d = 2; d < 18; d++) {
            ll val = d * 1LL * cnt;
            pfx[d] = pfx[d - 1] + val;
            cnt *= 10;
        }

        ll d = 1;
        while (d < 18 && pfx[d] <= k) {
            d++;
        }

        ll rem_offset = k - pfx[d - 1];
        ll digin_block = 10 * d;

        ll start_b = 1;
        for (ll i = 0; i < d - 2; i++) {
            start_b *= 10;
        }

        ll block_offset = rem_offset / digin_block;
        ll cur_block = start_b + block_offset; // exact block id
        ll rem_in_block = rem_offset % digin_block;

        ll num_idx = rem_in_block / d;
        ll digit_idx = rem_in_block % d; // fixed: % d

        ll actual_num = 0;
        if (cur_block % 2 == 0) {
            actual_num = 10 * cur_block + num_idx;
        } else {
            actual_num = (10 * cur_block + 9) - num_idx;
        }

        string s = to_string(actual_num);
        return s[digit_idx] - '0';
    }
};