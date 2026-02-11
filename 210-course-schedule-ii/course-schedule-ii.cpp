class Solution {
    #define pb push_back
    vector<int> ans;
    void bfs(int n,vector<int>&ind,vector<vector<int>>&adj){

            queue<int> q;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(ind[i]==0){
                    q.push(i);
                    ans.pb(i);
                    cnt++;
                }
            }

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for(auto nr : adj[cur]){
                    ind[nr]--;
                    if(ind[nr]==0){
                        q.push(nr);
                        ans.pb(nr);
                        cnt++;
                    }
                }
            }

       
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
      
        int n = numCourses;
        vector<int> ind(n,0);
        vector<vector<int>> adj(n);
        for(auto vec : pre){
            int a = vec[0];
            int b = vec[1];
            adj[b].pb(a);
            ind[a]++;
        }

         bfs(n,ind,adj);

         if(ans.size()==n) return ans;
         
         ans.clear();
         return ans;

    }
};