class Solution {
public:
    int mirrorDistance(int n) {
        
        int rev = 0;

        int temp = n;
        while( temp > 0){
            int rem = temp%10;
            rev = rev*10 + rem;
            temp /= 10;
        }

        return abs(n  - rev);
    }
};