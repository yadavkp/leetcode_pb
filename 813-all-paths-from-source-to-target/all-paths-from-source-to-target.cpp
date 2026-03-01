class Solution {
    vector<vector<int>> res;
   #define pb push_back
    int n;
    void dfs(int nod,vector<vector<int>>&graph,vector<int>&ans){
        ans.pb(nod);
        if(nod == n-1){
          
            res.pb(ans);
            return;
        }

        for(auto nr : graph[nod]){
            dfs(nr,graph,ans);
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         n = graph.size();
        vector<int> ans;
        
        dfs(0,graph,ans);

        return res;
    }
};