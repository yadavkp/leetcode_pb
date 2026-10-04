class Solution {
public:
    int minRotations(string s) {
        
        int cost = 0;
        int last = 0;
        for(char c : s){
            int cur = c - '0';
            cost += min(abs(last - cur), 10 - abs(last - cur));
            last = cur;
        }
        return cost;
    }
};