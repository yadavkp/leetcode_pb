class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        
        int n = a.size();
        vector<int> d(n,1);
        for(int i=1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(a[j] < a[i]){
                    d[i] = max(d[i],d[j]+1);
                }
            }
        }
        int ans = d[0];
        for(int i=1;i<n;i++){
            ans = max(ans,d[i]);
        }
        return ans;
    }
};