class Solution {

    bool dfs(int st,int end,vector<int>&vis, vector<vector<int>>&adj){
        vis[st] = 1;

        if(st == end)return true;

        for(auto nr : adj[st]){
            if(!vis[nr]){
                if(dfs(nr,end,vis,adj)) return true;
            }
        }

        return false;
    }


public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& query) {
        
        vector<vector<int>> adj(n);

        for(auto vec : pre){
            adj[vec[0]].push_back(vec[1]);
        }

        vector<bool> ans(query.size(),false);

        for(int j = 0;j<query.size();j++){
            auto vec = query[j];
            vector<int> vis(n,0);
            bool found = dfs(vec[0],vec[1],vis,adj);
            ans[j] = found;
        }

        return ans;
    
    }
};