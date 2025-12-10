#define ll long long
class Solution {
public:
    int reverse(int x) {

        int sign = (x < 0 ? -1 : 1);
        ll rev = 0,num = x;
        if(num < 0) num *= -1;
        
        while(num > 0){
            int rem = num%10;
            rev = rev * 10 + rem;
            num /= 10;
        }

        rev = rev * sign;
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }

        return (int)rev;
    }
};
