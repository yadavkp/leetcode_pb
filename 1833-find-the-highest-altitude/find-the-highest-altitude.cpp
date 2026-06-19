class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int mx = 0;
        int val = 0;
        for(int i=0;i<gain.size();i++){
            mx = max(mx, val + gain[i]);
            val = val + gain[i];
        }

        return mx;
    }
};