#define ll long long 
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
      

        int n = s.size();
          vector<vector<int>> frq(26);
        ll tot_sum = 0,mx_1char_sum = 0;
        for(int i=0;i<n;i++){
            frq[s[i]-'a'].push_back(cost[i]);
            tot_sum += cost[i];
        }

        for(auto &t : frq){
            ll sum = 0;
            for(auto val : t){
                sum +=val;
            }
            mx_1char_sum = max(mx_1char_sum,sum);
        }

        return (tot_sum - mx_1char_sum);
    }
};