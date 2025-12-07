class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> ans;
        for(int i=0;i<nums.size();i++){
            int rev = 0;
            int num = nums[i];
            int p = num;
            while(num > 0){
               rev = ((rev << 1) | (num&1) );
               num >>= 1;
            }
           
           
            ans.push_back({rev,p});
            
        }
        sort(ans.begin(),ans.end(),[&](const auto &a, const auto &b){
            if(a.first == b.first){
                return a.second < b.second ;
            } 
            return a.first < b.first;
        });
        vector<int> a;
        for(auto t : ans){
            a.push_back(t.second);
        }

        return a;
    }
};