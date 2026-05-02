class Solution {

    bool valid(int n){
        bool ok = false;
         while(n > 0){
            int rem = n%10;
            n /= 10;
            if(( rem == 4 || rem == 7||rem==3)){
                return false;
            }

            if(rem == 2 || rem == 5 || rem == 6 || rem == 9){
                ok = true;
            }
         }

        return ok & true;
    }
    
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++){

            if(valid(i))cnt++;
        }
        return cnt;
    }
};