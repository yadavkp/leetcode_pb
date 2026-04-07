class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>> vpp;

        for(int i=0;i<plantTime.size();i++){
            vpp.push_back({plantTime[i],growTime[i]});
        }

        auto cmp = [&](const pair<int,int>&a,const pair<int,int>&b){

            return a.second > b.second;
        };
        sort(vpp.begin(),vpp.end(),cmp);

        int grow = 0,bloom = 0;
        for(auto [p,g] : vpp){
            grow += p;
            bloom = max(bloom,grow + g);
        }

        return bloom;
    }
};