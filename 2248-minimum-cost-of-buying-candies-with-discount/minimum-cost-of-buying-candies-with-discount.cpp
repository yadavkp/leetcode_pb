class Solution {
public:
    int minimumCost(vector<int>& ct) {
        
        sort(ct.rbegin(),ct.rend());
        int n = ct.size();
        int cost = 0;
        for(int i=0;i<n;i++){
            cost += ct[i];
            if(i +1 < n){
                i++;
                cost += ct[i];
                i++;
            }
        }

        return cost;
    }
};