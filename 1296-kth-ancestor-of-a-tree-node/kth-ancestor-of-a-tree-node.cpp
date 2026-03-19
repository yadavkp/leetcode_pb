class TreeAncestor {
 

public:
    const static int N = 2e5;
    int dp[N][20];
     void dfs(int nod,int par,vector<vector<int>>&adj){
        dp[nod][0] = par;
        for(int i = 1;i<=19;i++){

           if(dp[nod][i-1] >0){
                dp[nod][i] = dp[dp[nod][i-1]][i-1];
            }

        }

        for(auto child : adj[nod]){
            if(child == par)continue;
            dfs(child,nod,adj);
        }
     }
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            
            if(parent[i] != -1){
                adj[i+1].push_back(parent[i]+1);
                adj[parent[i]+1].push_back(i+1);
            }
            
        }
        memset(dp, 0, sizeof(dp));
        dfs(1,0,adj);
    }
    
    int getKthAncestor(int nod, int k) {
        nod += 1;
        for(int i = 19;i>=0;i--){

            if((k >> i)& 1){
                if(nod==0) return -1;
                nod = dp[nod][i];
            }

        }

        return (nod == 0 ? -1 : nod-1);
    }
};


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */