class Solution {
    #define ll long long
public:
    long long countCommas(long long n) {
        ll st = 1000;
        ll comma = 1;
        ll tot_comma = 0;
        while(st <= n){
            
            ll next_range = st * 1000;
            ll min_num = min(n,next_range-1);
            
            ll curr_range =  min_num - st + 1;
            tot_comma += curr_range * comma;

            st = next_range;
            comma++;
        }
        return tot_comma;
    }
};