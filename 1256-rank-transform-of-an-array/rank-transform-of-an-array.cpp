class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        if(arr.size() <=0) return {};
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());

        map<int,int> mp;
        int cnt = 1;
        mp[temp[0]] = 1;
        for(int i=1;i<temp.size();i++){
            if(temp[i] != temp[i-1]){
                mp[temp[i]] = ++cnt;
                
            }
        }

        for(int i=0;i<arr.size();i++){
            int f = mp[arr[i]];
            arr[i] = f;
        }

        return arr;
    }
};