class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string ans ;
        for(int i=0;i<words.size();i++){
            int sum = 0;
            for(auto ch : words[i]){

                sum += weights[ch-'a'];
                
            }
            sum %= 26;
            ans += ((26 - sum-1)+ 'a');
        }
        return ans;
    }
};