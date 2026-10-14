class Solution {
public:
    string maxSumOfSquares(int len, int sum) {

       if(sum > 9*len)return "";

        string res = "";
        for(int i=0;i<len;i++){
            int digit = min(9,sum);
            res += to_string(digit);
            sum -= digit;
        }
        return res;
        
    }
};