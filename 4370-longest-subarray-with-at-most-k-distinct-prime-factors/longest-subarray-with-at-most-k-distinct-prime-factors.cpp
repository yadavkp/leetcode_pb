class Solution {

    void factor(map<int,int>&mp,int num,int flag){

        

        for(int i = 2;i *i <= num;i++){

            if( num %i ==0){
                while(num%i==0){
                    
                    if(flag==1){
                        mp[i]--;
                        if(mp[i]==0)mp.erase(i);
                    }else{
                        mp[i]++;
                    }
                    num /= i;
                }
            }
        }
        if(num > 1 && flag==1){
            mp[num]--;
            if(mp[num]==0)mp.erase(num);
        }else if(num>1){
            mp[num]++;
        }
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        
        map<int,int> mp;

        int l = 0,r = 0,n = nums.size();
        int ans = 0;
        for(;r <n; r++){

            factor(mp,nums[r],0);

            while(mp.size()>k){
                factor(mp,nums[l++],1);
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};