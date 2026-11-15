class Solution {
public:
    int countConsistent(vector<int>& a) {
        
        int cnt = 0;
        int n = a.size();

        for(int i=0;i<n;i++){
            int mn = a[i];
            int a_nd = a[i];
            for(int j=i;j <n;j++){
                mn = min(mn,a[j]);
                a_nd = a_nd & a[j];

                if(mn == a_nd)cnt++;
            }
        }
        return cnt;
    }
};