class Solution {
    #define pb push_back
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans;
        for(auto t : nums){
            if(t==2){
                ans.pb(-1);
                continue;

            }
            int left = 0;
            for(int i=0;i<31;i++){

                if((t&(1 << i)) == 0){
                     left -= (1 << (i-1));
                     for(int j = i+1;j<31;j++){
                        if((t & (1 << j)))left += (1 << j);
                     }
                     ans.pb(left);
                     break;
                    
                }else{
                    left += (1 << i);
                }
               
            }
            

        }
        return ans;
    }
};