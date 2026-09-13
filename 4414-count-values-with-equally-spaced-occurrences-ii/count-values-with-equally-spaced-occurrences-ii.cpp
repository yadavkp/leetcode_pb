class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        
        map<int,vector<int>> ind;
    int n  = nums.size();
        for(int i=0;i < n;i++){
           
            ind[nums[i]].push_back(i);
        }
        int cnt=0;
        for(auto [va,v] : ind){
            if(v.size()>=3){
                int diff = v[1] - v[0];
                int f = 1;
                for(int i=1;i < v.size();i++){
                    if(v[i]-v[i-1] != diff)f = 0;
                }
                if(f)cnt++;
            }
        }

        return cnt;
    }
};