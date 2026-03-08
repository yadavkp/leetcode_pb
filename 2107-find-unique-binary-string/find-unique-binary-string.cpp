class Solution {

    void pre_gen_g_cod(int n,vector<string>&ans){

       for(int mask = 0; mask < (1 << n);mask++){
         string s ;
         for(int j = 0;j<n;j++){
            s += (((mask >> j) == 1) ? "1" : "0");
         }
         ans.push_back(s);
       }

    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        // step generate gray code, then , do work 
        int n = nums.size();
        vector<string> ans;
        pre_gen_g_cod(n,ans);
        set<string> temp(ans.begin(),ans.end());
        
        for(auto it : nums){
             if(temp.count(it)){
               
                temp.erase(it);
                
             }
        }
       
        return *temp.begin();

    }
};