class Solution {
    
    bool bfs(int n,vector<int>&ind,vector<vector<int>>&adj){

        queue<int> q;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
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
                    cnt++;
                }
            }
        }

        return cnt == n;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        #define pb push_back
        int n = numCourses;
        vector<int> ind(n,0);
        vector<vector<int>> adj(n);
        for(auto vec : pre){
            int a = vec[0];
            int b = vec[1];
            adj[b].pb(a);
            ind[a]++;
        }

        return bfs(n,ind,adj);

    }
};