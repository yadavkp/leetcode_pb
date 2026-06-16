class Solution {

    bool check(unordered_map<int,int>&frq,int len){

        int mx_frq = 1, cnt = 0;
        for(auto [v,f] : frq){
            mx_frq = max(mx_frq,f);
        }

        if(frq.size() == len) return false;
       
         for(auto [v,f] : frq){
            if(mx_frq != f)cnt++;
        }

        if(cnt < 1 && frq.size()>1)return false;
        // this for checking atleast having two num with different frequecny
       
        for(auto [v,f] : frq){
            if(mx_frq != f){
                if(mx_frq != 2* f) return false;
            }
        }

        return true;

    }
public:
    int getLength(vector<int>& nums) {
        
        int mx = 1;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> frq;
            int mx_frq = 0;
            for(int j = i;j<nums.size() ; j++){
                frq[nums[j]]++;
                mx_frq = max(mx_frq,frq[nums[j]]);
                if(frq.size()==1){
                    mx = max(mx, j-i+1);
                    continue;
                }
                if(mx_frq%2 == 0 && check(frq,j-i+1)){
                    mx = max(mx, j - i +1);
                }
            }
        }

        return mx;
    }
};