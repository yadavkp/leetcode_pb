class Solution {
public:
    int minInsertions(string s) {
        
        int op = 0,cl=0,n = s.size(),cost=0;

        for(int i=0;i < n;i++){
            char ch = s[i];
            if(ch == '('){
               op++;
            }else{
                
                if(i+1 < n && s[i+1]==')'){
                    i++;
                    if(op>0)op--;
                    else cost += 1;
                }else{

                    cost++;
                    if(op > 0)op--;
                    else cost++;
                }
            }
        }
        cost += (op*2);
        return cost;
        
    }
};