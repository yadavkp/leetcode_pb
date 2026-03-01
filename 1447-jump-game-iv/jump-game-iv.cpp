class Solution {
    int n;
    vector<int> vis;
    bool ok = false;
    
    unordered_map<int,vector<int>> mp;
        
        void store_similar_nod(int idx,vector<int>&a,queue<int>&q){
        
            for(auto j : mp[a[idx]]){
                   
                        if(!vis[j]){
                            if(j == n-1)ok = true;
                            q.push(j);
                            vis[j] =1;
                        }
                    
            }
            mp[a[idx]].clear();
             
        }

        
public:
    int minJumps(vector<int>& a) {

        n = a.size();
        vis.assign(n,0);
        for(int i=0;i<n;i++){
            mp[a[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
      
        int cnt = 0;
        while(!q.empty()){

            int sz = q.size();
            while(sz--){

                int idx = q.front(); q.pop();
                if(idx == n-1) return cnt;

                if(idx-1 >= 0 && !vis[idx-1]){
                        q.push(idx-1);
                        vis[idx-1] = 1;
                }

                if(idx >= 0 && idx+1 < n && !vis[idx+1]){
                        q.push(idx+1);
                        vis[idx+1] = 1;
                }

                 store_similar_nod(idx,a,q);
            }
            cnt++;
        }
        return -1;
    }
};