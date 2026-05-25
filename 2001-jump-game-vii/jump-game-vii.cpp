class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int p = minJump,q = maxJump,n = s.size();
        vector<int> reach(n,0);
        set<int> seen;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                seen.insert(i);
            }
        }
        reach[0] =1;
         for(int i=0;i<n;i++){
            if(reach[i]){
                int mn = i + p,mx = i+q;
                auto lb =seen.lower_bound(mn);
                auto up = seen.upper_bound(mx);
                
                if(lb == seen.end()) continue;
                
                while(!seen.empty() && lb != up ){
                    
                    auto nex= next(lb);
                    reach[*lb] = 1;

                    seen.erase(lb);
                    lb = nex;
                }
            }
           
        }

        return reach[n-1]==1;

    }
};