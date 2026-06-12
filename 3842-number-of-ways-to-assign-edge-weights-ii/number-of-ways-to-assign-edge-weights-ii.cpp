class Solution {
    #define ll long long 
    vector<int> depth;
   static  const int LOG = 20;
   static const  int N = 2e5+10;
    int dp[N][LOG];
   static   const int mod  = 1e9 + 7;

public:
    void dfs(int nod, int par,  vector<vector<int>>&adj){

        dp[nod][0] = par;

        for(int i=1;i<20;i++){
            if(dp[nod][i-1] != 0){
                dp[nod][i] = dp[dp[nod][i-1]][i-1];
            }
        }


        for(auto child : adj[nod]){

                if(child  == par)continue;

                    depth[child]= depth[nod]+1;
                    dfs(child, nod, adj);
                
        }
    }
    
    

    int get_kth_par(int nod,int k){

        for(int i=19;i>=0;i--){
            if((k >> i) & 1){
                nod = dp[nod][i];
            }
        }

        return nod;
    }

    int find_lca(int a,int b){
        if(a == b) return a;

        for(int i=19;i>=0;i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        return dp[a][0];
    }

    ll mul ( ll a, ll b, ll mod){

        a %= mod;
        ll res = 1;
        while(b > 0){
            if(b&1){
                res = (res * a) % mod;
            }
            a = (a * a) % mod;

            b >>= 1;
        }
        
        return res;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        int n = edges.size();
        depth.assign(n+2,0);
        vector<vector<int>> adj(n+2);
       
        for(auto vec : edges){
            int u = vec[0],v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1,0,adj);

        int sz = query.size();
        vector<int> ans(sz);
        int i = 0;
        for(auto vec : query){

            int u = vec[0],v = vec[1];
            
            if(depth[u] > depth[v]) swap(u,v); // make sure v > a

            int diff = depth[v] - depth[u];
            
            int same_level_v = get_kth_par(v,diff);

            if(u == v){
                ans[i++] = 0;continue;
            }
            int l_c_a = find_lca(u,same_level_v);

            int dist = depth[u] + depth[v] - 2 * depth[l_c_a];
            
            ans[i++] = mul(2,dist-1,mod);
        }

        return ans;

    }
};