class Solution {
public:
    int earliestFinishTime(vector<int>& ltime, vector<int>& ldrn, vector<int>& wtime, vector<int>& wdrn) {

        int ans = 1e9;

        int n = ltime.size();

        for(int i=0;i<n;i++){
            int cur = ltime[i] + ldrn[i];

            for(int j = 0;j<wtime.size();j++){
                int neww = max(cur, wtime[j]);
                
                ans = min(ans, neww + wdrn[j]);
            }
        }


        for(int i=0;i<wtime.size();i++){
            int cur = wtime[i] + wdrn[i];
            cout<<cur<<" ";
            for(int j = 0;j<n;j++){
                int neww = max(cur, ltime[j]);
                ans = min(ans, neww + ldrn[j]);
                cout<<ans<<" ";
            }
        }



        return ans;
        
    }
};