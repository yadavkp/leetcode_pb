class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        vector<vector<int>> ans;
        #define all(x) x.begin(),x.end()
        sort(all(arr));

        int d = 1e7;
        for(int i=1;i<arr.size();i++){
            d = min(d,arr[i] - arr[i-1]);
        }

        for(int i=1;i<arr.size();i++){
           if(d == arr[i] - arr[i-1]){
            ans.push_back({arr[i-1],arr[i]});
           }
        }

        return ans;
        
    }
};