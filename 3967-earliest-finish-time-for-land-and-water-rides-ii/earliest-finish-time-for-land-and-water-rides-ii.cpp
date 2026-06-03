class Solution {
public:
   int earliestFinishTime(vector<int>& ltime, vector<int>& ldrn, vector<int>& wtime, vector<int>& wdrn) {
        

         int ans = 1e9;

        int n = ltime.size(),m = wtime.size();

        
        int start = 1e9;
        for(int i=0;i<n;i++){
            // int start = ltime[i] + ldrn[i];
            start = min(start, ltime[i] + ldrn[i]);
        }

        for(int i=0;i<m;i++){
            ans = min(ans,max(start,wtime[i]) + wdrn[i]);
        }

        start = 1e9;

        for(int i=0;i<m;i++){
            start = min(start, wtime[i] + wdrn[i]);
        }

        for(int i=0;i<n;i++){
             ans = min(ans,max(start,ltime[i]) + ldrn[i]);
        }

        return ans;
    }
};