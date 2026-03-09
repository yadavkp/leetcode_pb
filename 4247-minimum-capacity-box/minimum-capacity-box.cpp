class Solution {
public:
    int minimumIndex(vector<int>& cap, int itemSize) {
        
        int idx = -1,mn = 1e9;
        for(int i=0;i<cap.size();i++){
            if(cap[i] >= itemSize){
                if(mn > (cap[i]-itemSize)){
                    mn = (cap[i]-itemSize);
                    idx = i;
                }
            }
        }

        return idx;
    }
};