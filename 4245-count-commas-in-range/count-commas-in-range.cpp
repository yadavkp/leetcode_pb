class Solution {
public:
    int countCommas(int n) {
        if(n < 1000){
            return 0;
        }
        int cnt = n - 1000 + 1;

        return cnt;
    }
};