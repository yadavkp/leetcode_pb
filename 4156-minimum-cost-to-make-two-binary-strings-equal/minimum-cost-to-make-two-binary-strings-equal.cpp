#define ll long long 
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.size();
        ll ans = 0;
        ll a =0,b = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0' && t[i]=='1')a++;
            else if(s[i]=='1' && t[i]=='0')b++;
        }
        flipCost = (ll)flipCost;
        swapCost = (ll)(swapCost);
        crossCost = (ll)(crossCost);
        
        ans += (min(a,b)*(min(swapCost,2*flipCost))); // 2pos will equal so 2*flip
       int pair = min(a,b);
        a -= pair;
        b -= pair;
      
        ll rem = 0;
        if(a  > 0)rem = a;
        else rem = b;
        int bcha = rem%2;
        rem -= bcha;
       
        rem /= 2; // because , 1 cc, and 1 swap , make two posn equal so devide/2;
        ans += (rem*(min(crossCost + swapCost,2*flipCost)));

        if(bcha==1) ans += flipCost;

        return ans;
    }
};


