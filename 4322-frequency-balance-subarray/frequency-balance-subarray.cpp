class Solution {

    bool check(unordered_map<int,int>&frq,int mx_frq){
        int half = mx_frq/2;
        int ok1 = 0,ok2 = 0; // for half, and mx_frq;
       
       
        for(auto [v,f] : frq){
            if(mx_frq != f){
                if(mx_frq != 2* f) return false;
            }
            if(f == half)ok1 = 1;
            if(mx_frq == f)ok2=1;
        }
        if(ok1==0 || ok2==0) return false; // if anyone not present 

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
                if(mx_frq%2 == 0 && check(frq,mx_frq)){
                    mx = max(mx, j - i +1);
                }
            }
        }

        return mx;
    }
};