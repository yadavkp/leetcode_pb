class Solution {
public:
    int countPartitions(vector<int>& a) {
        int n = a.size();
        vector<int> pfx(n,0),sfx(n,0);

        pfx[0] = a[0];
        sfx[n-1] = a[n-1];
        for(int i=1;i<n;i++){
            pfx[i]  = pfx[i-1] + a[i];
            sfx[n-i-1] = sfx[(n-i)] + a[n-1-i];
        }
        int cnt = 0;
        for(int i=0;i<n-1;i++){
            if(abs(pfx[i] - sfx[i+1])%2 == 0)cnt++;
        }

        return cnt;
    }
};