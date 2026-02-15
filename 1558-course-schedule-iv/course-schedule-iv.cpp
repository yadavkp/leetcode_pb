
// m-1 ->  by dfs
// m - 2 _>  by bfs
// m-3 ->    by topoorder
// m-4 ->  by the preprocess preq in the matrix , check is it true or not



class Solution {

public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& query) {
        
        vector<vector<int>> adj(n);

        vector<int> ind(n,0);
        for(auto vec : pre){
            adj[vec[0]].push_back(vec[1]);
            ind[vec[1]]++;
        }
            queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i] == 0)q.push(i);
        }

        vector<bool> ans(query.size(),false);

        unordered_map<int,set<int>> mp;

        while(!q.empty()){

            auto cur = q.front(); q.pop();

            for(auto nr : adj[cur]){
                ind[nr]--;
                if(ind[nr]==0)q.push(nr);

                mp[nr].insert(cur);
                // proces prerequiset
                for(auto preq : mp[cur]){
                    mp[nr].insert(preq);
                }
            }
        }

        for(int j = 0;j<query.size();j++){
            auto vec = query[j];
            int u = vec[0],v = vec[1];
            bool fnd = mp[v].count(u);
            ans[j] = fnd;
        }

        return ans;
    
    }
};

// class Solution {

   
//     bool bfs(int st,int end, vector<int>&vis , vector<vector<int>>&adj){

//         queue<int> q;q.push(st);

//         vis[st] = 1;
        

//        while(!q.empty()){

//             auto cur = q.front(); q.pop();

//             if(cur == end)return true;

//              for(auto nr : adj[cur]){
                
//                  if(!vis[nr]){
//                     q.push(nr);
//                     vis[nr] = 1;
//                  }
//             }
//        }

//         return false;
//     }

// public:
//     vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& query) {
        
//         vector<vector<int>> adj(n);

//         for(auto vec : pre){
//             adj[vec[0]].push_back(vec[1]);
//         }

//         vector<bool> ans(query.size(),false);

//         for(int j = 0;j<query.size();j++){
//             auto vec = query[j];
//             vector<int>vis(n,0);
//             bool found = bfs(vec[0],vec[1],vis,adj);
//             ans[j] = found;
//         }

//         return ans;
    
//     }
// };



// class Solution {

//     bool dfs(int st,int end,vector<int>&vis, vector<vector<int>>&adj){
//         vis[st] = 1;

//         if(st == end)return true;

//         for(auto nr : adj[st]){
//             if(!vis[nr]){
//                 if(dfs(nr,end,vis,adj)) return true;
//             }
//         }

//         return false;
//     }


// public:
//     vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& query) {
        
//         vector<vector<int>> adj(n);

//         for(auto vec : pre){
//             adj[vec[0]].push_back(vec[1]);
//         }

//         vector<bool> ans(query.size(),false);

//         for(int j = 0;j<query.size();j++){
//             auto vec = query[j];
//             vector<int> vis(n,0);
//             bool found = dfs(vec[0],vec[1],vis,adj);
//             ans[j] = found;
//         }

//         return ans;
    
//     }
// };