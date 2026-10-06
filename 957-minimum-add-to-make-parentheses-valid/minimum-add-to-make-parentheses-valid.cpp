class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int cost = 0,op=0,cl=0;
        int n = s.size();
        for(int i = 0;i < n;i++){

            if(s[i] == '('){
                op++;
                if(cl>0){
                    cost += cl;cl=0;
                }
            }else{
                if(op>0){
                    op--;
                }else{
                    cl++;
                }
            }
        }
        cost += op;cost +=cl;
        return cost;
    }
};