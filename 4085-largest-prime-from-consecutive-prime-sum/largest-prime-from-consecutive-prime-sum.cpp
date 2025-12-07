 #define ll long long 
class Solution {
        vector<bool> arr;
    void findall(int n, vector<int>& prime){
       arr.assign(n+1,true);
        arr[0]=false,arr[1]=false;
        if(n < 2) return;
        for(ll i = 2;i*i<= n;i++){
            if(arr[i]==true){
                for(ll j = i+i;j <= n;j+=i){
                    arr[j] = false;
                }
            }
        }
       
    }
public:
    int largestPrime(int n) {
        if(n < 2) return 0;
        vector<int> prime;
        findall( n, prime);
           
         for(int i = 0;i<=n;i++){
            if(arr[i]==true){
                prime.push_back(i);
            }
        }
       
            int mx = prime[0];
            ll pfx = prime[0];
            for(int i=1;i<prime.size();i++){
                if(arr[pfx]==true){
                    mx = (int)pfx;
                }
                pfx += prime[i];
                if(pfx > n ) break;
            }
            return mx;
    }
};