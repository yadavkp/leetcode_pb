class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(),nums.end());
        int mx = 0,cnt = 0;
        for(auto t : seen){
            int num = t;
            if(seen.count(t-1)==0){
                cnt = 1;
                 while(seen.count(++num)){
                    cnt++;
                  
                }
                 mx = max(mx,cnt);
                if(mx > (nums.size()-mx))break;
            }   
        }
        return mx;
    }
};