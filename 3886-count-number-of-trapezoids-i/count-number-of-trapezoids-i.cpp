class Solution {
    int M = 1e9+7;
    #define ll long long 
public:
    int countTrapezoids(vector<vector<int>>& points) {
        
        unordered_map<int,int> mp;
        // count points on y coordinate
        for(auto &point : points){
            int y = point[1];
            mp[y]++;
        }

        ll result = 0;
        ll prev_hz_line = 0;

        for(auto &it : mp){

            ll count = it.second;

            ll hz_line = count*(count-1)/2;

            result += (hz_line * prev_hz_line);

            prev_hz_line += hz_line;
        }

        return result % M;
    }
};