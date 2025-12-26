class Solution {
public:
    int minDeletionSize(vector<string>& st) {
        
        int cnt = 0;
        int n = st[0].size();
        for(int i=0;i<n;i++){
            char ch = st[0][i];
            for(auto &t : st){
                if(ch <= t[i]){
                   ch = t[i];
                }else{
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};