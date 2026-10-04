class Solution {
public:
    int minRotations(int n, string s) {
    int cost = 0,last = 0;
        for(int j=0;j<n;j++){
            int cur  =s[j]-'0';
            cost += min(abs(last - cur),10 - abs(last - cur));
            last = cur;
        }
        int ans = cost;
        last = 0;
        int end = s[n-1]-'0';
        for(int j=0;j<n-1;j++){
            int cur  =s[j]-'0';
            int val = ans;
            val -= min(abs(last -cur),10 - abs(last -cur));
            val += min(abs(last - end),10 - abs(last - end));
            cost = min({cost,val});
            last = cur;
        }

        return cost;
    }
  
};