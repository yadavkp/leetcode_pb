class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char,int> frq;
        int mx = 1e5;
        for(auto ch : text){
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch=='n'){
                frq[ch]++;
            }
        }
        mx = min({mx, frq['b'],frq['a'],frq['l']/2,frq['o']/2,frq['n']});
        

        return mx;
    }
};