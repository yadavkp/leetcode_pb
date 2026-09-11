class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        

        vector<int> frq(10,0);
        for(int v : digits){
            frq[v]++;
        }
        int tot = 0;

        for(int i=100;i <= 999;i+=2){

            
                vector<int> frq1(10,0);
                string s = to_string(i);
                for(int j = 0;j < 3;j++){
                    frq1[s[j]-'0']++;
                }
                int cnt = 1;
                for(int j = 0;j < 3;j++){
                    int val = s[j]-'0';
                    if( frq1[val] > frq[val]) cnt = 0;;
                }
                tot += cnt;
            
        }
        return tot;
    }
};