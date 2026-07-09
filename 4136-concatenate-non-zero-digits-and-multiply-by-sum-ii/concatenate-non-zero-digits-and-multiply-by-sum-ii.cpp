class Solution {
    #define ll long long 
    int mod = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& qry) {
        
        int n = s.size();

        vector<ll> dig_sum(n,0);
        vector<ll> build_num(n,0);
        vector<ll> dig_count(n,0);
        vector<ll> pow10(n,0);
        pow10[0] = 1;
        for(int i=1;i<n;i++){
            pow10[i] = (pow10[i-1] * 10) % mod;
        }
        dig_count[0] = (s[0]-'0' == 0) ?0 : 1;
        dig_sum[0] = (s[0]-'0');
         for(int i=1;i<n;i++){
            int dig = s[i]-'0';
            if(dig != 0)dig_count[i] = dig_count[i-1] + 1;
            else dig_count[i] = dig_count[i-1];
            // dig sum 
            dig_sum[i] = (dig_sum[i-1] + dig) % mod;
        }
        // build num;
        build_num[0] = (s[0]-'0');
        for(int i=1;i<n;i++){
            int dig = s[i]-'0';
            if(dig != 0){
                build_num[i] = ((build_num[i-1] * 10) % mod + dig) % mod;
            }else build_num[i] = build_num[i-1];
        }
            int q = qry.size();
            vector<int> ans(q,0);
            for(int i=0;i<q;i++){
                int l = qry[i][0],r = qry[i][1];

                ll sum = dig_sum[r] - ( (l==0) ? 0 : dig_sum[l-1]);
                int k = dig_count[r] - ( (l==0) ? 0 : dig_count[l-1]);

                ll left_num = 0;
                if(l){
                  left_num =  ( build_num[l-1] * pow10[k] ) % mod;
                }
                ll num =( build_num[r] - left_num + mod ) % mod;

                ans[i] = (sum * num ) % mod;
            }

            return ans;
    }
};