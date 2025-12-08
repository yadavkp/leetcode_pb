class Solution {
public:
    int countTriples(int n) {
        
        auto square= [&](int n)-> bool
        {
            int num = (int)sqrt(n);
           
            return (num*num == n);
           
            

        };

        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                int sum = i*i + j*j;
                if(square((sum))){
                    int c = (int)sqrt(sum);
                    if(c <= n){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};