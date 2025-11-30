class Solution {
    #define ll long long
public:
    int minSubarray(vector<int>& a, int p) {
        int n = a.size();
        int len = n ;
        ll total = accumulate(a.begin(),a.end(),0LL);
        if(total%p==0){
            return 0;
        }
        unordered_map<int,int> last;
        last[0] = -1;

        int  pfx = 0;
        int need  = (total%p);
        for(int j=0;j<n;j++){
            pfx += a[j];
            pfx%= p;
            int target = (pfx - need + p)%p;
            if(last.count(target)){
                len = min(len, j - last[target]);
            }
            last[pfx] = j;
        }
        return (len == n ? -1 : len);
    }
};