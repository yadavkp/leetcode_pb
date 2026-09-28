class Solution {

    bool check(vector<int>&nums,int l,int r){

        vector<int> frq(501,0);
        for(int i = l;i <=r;i++){
            frq[nums[i]]++;
        }

        for(int i=0;i < 501;i++){
            if(frq[i]==0)continue;
            frq[i]--;
            for(int j = 0;j < 501;j++){
                if(frq[j]==0)continue;

                frq[j]--;
                int val = i + j;
                
                if( val <= 500 && frq[val] > 0){
                    return true;
                }
               
                frq[j]++;
            }
            frq[i]++;
        }
        return false;
    }
public:
    int maxSubarray(vector<int>& nums) {
        
        int ans = 0;
        int i=0,j = 0;
        int n = nums.size();
        ans = min(2,n);
        
        while(j < n ){
            
            if(check(nums,i,j)){
                i++,j++;
            }else{
                ans = max(ans, j - i + 1);
                j++;
            }
           

        }
        return ans;
    }
};