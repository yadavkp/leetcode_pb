class Solution {
    
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        
        auto cmp = [&](auto &a, auto &b){

            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(env.begin(),env.end(),cmp);


        vector<int> lis;
        for(int i = 0;  i < env.size(); i++){

            int ht = env[i][1];

            auto it = lower_bound(lis.begin(), lis.end(), ht);

            if(it == lis.end() ){
                lis.push_back(ht);
            }
            else{
                *it = ht;
            }
        }

        return lis.size();

    }
};