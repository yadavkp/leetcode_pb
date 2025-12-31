#define ll long long 
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        

        ll ans = 0;

        if(cost1 + cost2 >= costBoth){
            ans += (min((ll)need1,(ll)need2)) * costBoth;
            if(need1 > need2)ans += (need1 - need2)*1LL*(min(cost1,costBoth));
            else{
                ans += (need2-need1)*1LL*(min(cost2,costBoth));
            }
        }else{
            ans += cost1 * 1LL*need1  + cost2 *1LL * need2;
        }

        return ans;
    }
};