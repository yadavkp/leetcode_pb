class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        vector<int> frq(3,0);

        for(int i=0; i < n; i++){
            frq[stones[i]%3]++;
        }

        if(frq[0] %2 == 0){
            return frq[1] > 0 && frq[2];
        }else{

            return abs(frq[1] - frq[2]) > 2;
        }
        
    }
};