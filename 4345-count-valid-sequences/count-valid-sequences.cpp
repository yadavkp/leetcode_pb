class Solution {
    #define ll long long 
    int all_odd_count = 0,tot_ways = 0,even_ways=0;
    const int static N = 5* 1e5 + 1;
    const ll static  mod = 1e9 +7;

    
    ll fact[N],inv_fact[N];
    ll pow(ll base,ll expo,ll mod){

        ll res  =1;
        
        base %= mod;

        while(expo > 0){

            if(expo & 1){
                res = (res * base) % mod;
            }

            base = (base * base) % mod;

            expo >>= 1;
        }

        return res;
    }
   void  precompute(int n, int k){

        fact[0] = 1;

        for(int i=1; i<=n;i++){
            fact[i] = (fact[i-1] * i) % mod;
        }

        inv_fact[n-1] =  pow(fact[n-1],mod-2,mod);

        for(int i=n-2; i>=0;i--){
            inv_fact[i] = (inv_fact[i+1] * (i+1)) % mod;
        }

    }
    ll ncr(ll n, ll r){

        return fact[n] * inv_fact[r] % mod * inv_fact[n-r] % mod;
    }
public:
    int countValidSequences(int n, int k) {
        
        precompute(n,k);
        if(n - k < 0 || (n - k)%2){
            all_odd_count = 0;
        }else{
            all_odd_count = ncr((n + k)/2 - 1, k - 1);
            
        }
        tot_ways = ncr(n-1,k-1);
        even_ways = (tot_ways - all_odd_count + mod) % mod;

        return even_ways;
    }
};