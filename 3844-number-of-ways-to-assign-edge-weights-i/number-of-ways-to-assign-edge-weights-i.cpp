class Solution {
     int N = 2e5;
    vector<int> depth;
    int mx_depth = 0;
    const int mod = 1e9 + 7;
    #define ll long long
    void dfs(int nod,vector<vector<int>>&adj,vector<int>&vis){

        vis[nod] = 1;
        for(auto nr : adj[nod]){
            if(!vis[nr]){

                depth[nr] = depth[nod]+1;
                mx_depth = max(mx_depth, depth[nr]);
                dfs(nr,adj,vis);
            }
        }
    }

    ll tot_ways(ll a,ll b,ll mod){

        ll res = 1;
        a %= mod;
        while(b > 0){

            if(b&1){
                res = (res * a) % mod;
            }
            a = (a * a ) % mod;
            b >>= 1;
        }

        return  res;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n+2);
        vector<int> vis(n+2,0);

        depth.assign(N,0);

        for(auto &vec : edges){
            int u = vec[0],v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1,adj,vis);

        return tot_ways(2,mx_depth-1,mod);


    }
};