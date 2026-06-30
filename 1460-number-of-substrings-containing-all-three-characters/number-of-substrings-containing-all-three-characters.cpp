//  think about , if u generate substring , from i and  expand j,
//  then think, if u stood on i, how many substring can make from 0 to i
// its very easy to track, last index of a,b,c all then take min +1

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int a=-1,b=-1,c=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')a = i;
            else if(s[i] == 'b')b = i;
            else if(s[i]=='c') c=i;

            if(a != -1 && b != -1 && c != -1){
                cnt += (min({a,b,c})) + 1;
            }
        }

        return cnt;
    }
};