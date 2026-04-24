class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int mx = 0,l=0,r=0;
        int space= 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L')l++;
            if(moves[i]=='R')r++;

            if(moves[i]=='_')space++;

            
        }

        return mx = max(mx, abs(l - r) + space);
    }
};