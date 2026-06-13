

// class Solution {
//     #define ll long long 
//     ll mx_total = 0;
// public:
//     long long maxTotalValue(vector<int>& nums, int k) {
//         int n = nums.size();
//        vector<int> ans;
       
//         for(int i=0;i<n;i++){
//              int mn = 1e9,mx = 0;
//             for(int j=i+1;j<n;j++){
//                 mx = max({mx,nums[i],nums[j]});
//                 mn = min({mn,nums[i],nums[j]});
//                 ans.push_back(mx-mn);
//             }
//         }
//         sort(ans.rbegin(),ans.rend());
//         for(int i=0;i< min((int)ans.size(),k);i++){
//             mx_total += ans[i];
//         }
//         return mx_total;
//     }
// };




// method 2 ->  for this pb here u can find the better ans 


class Solution {
    #define ll long long 
    ll mx_total = 0;
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        int K = log2(n) + 1; // just colm have to made

        vector<vector<int>> range_max(n, vector<int>(K+1));
        vector<vector<int>>  range_min(n, vector<int>(K+1));

        // first fill base cases for sparse table 
        for(int i = 0;i < n;i++) range_max[i][0] = range_min[i][0] = nums[i];

        for(int j = 1; j <= K;j++){
            for(int i = 0; i + (1 << j) <= n; i++){
                range_max[i][j] = max(range_max[i][j-1], range_max[i + (1 << (j-1))][j-1]);
                range_min[i][j] = min(range_min[i][j-1], range_min[i + (1 << (j-1))][j-1]);
            }
        }

        auto max_query = [&](int l,int r){
            int j = log2(r - l + 1); // power of 2, that fit inside the len (r - l +1)/
            return  max(range_max[l][j] ,range_max[r - (1 << j) + 1][j]);
        };

        auto min_query = [&](int l,int r){
            int j = log2(r - l + 1);
            return min( range_min[l][j] ,range_min[r - (1 << j) + 1][j]);
        };

        auto value = [&](int l,int r){

            return (max_query(l,r) - min_query(l,r));
        };

        // fill the heap 
        priority_queue<tuple<ll,int,int> > heap; //  max heap 
// fill the heap 
        for(int l = 0; l < n; l++){
            heap.push({value(l,n-1),l,n-1});
        }

        while(k--){

            auto [val, l, r ]  = heap.top(); heap.pop();
            mx_total += val;

            if(r > l) heap.push({value(l,r-1), l, r-1}); // might value possible in the smaller range 
        }

        return mx_total;



    }
};