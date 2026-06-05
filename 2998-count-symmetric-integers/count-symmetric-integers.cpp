class Solution {

    int check (string s){

        int sum1 = 0, sum2 = 0;
        for(int i=0;i<s.size();i++){
           
            if(i < ( s.size() / 2)){
                sum2 += (s[i]-'0');
            }else{
                 sum1 += (s[i]-'0');
            }
        }        
        return (sum1 == sum2);
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt= 0;
        for(int l = low;l <= high;l++){

            string s = to_string(l);
            if(s.size() %2==0){
               cnt +=  check(s);
            }
        }

        return cnt;
    }
};