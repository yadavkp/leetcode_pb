
class Solution {
    #define ll long long
    #define pb push_back
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<ll,ll>>>  adj(n);
        k = k+1;

        for(auto vec : flights){

            int u = vec[0],v = vec[1],w = vec[2];
            adj[u].pb({w,v});
        }
        
        using T = tuple<ll,ll,ll>;
        priority_queue<T, vector<T> , greater<T> > pq;

        vector<vector<ll>> dist(n,vector<ll>(k+2,1e18));

        dist[src][0] = 0;
        pq.push({0,0,src}); // dist,k,u/

        while(!pq.empty()){
            auto [d,kk,u] = pq.top(); pq.pop();

            if(u == dst)return d;

           // if(d > dist[u][kk]) continue;

            for(auto [w,v] : adj[u]){

                if(kk + 1 <= k){
                    if(dist[v][kk+1] > dist[u][kk] + w){
                        dist[v][kk+1] = dist[u][kk] + w;
                        pq.push({dist[v][kk+1],kk+1,v});
                    }
                }
            }
        }
        return -1;
    }
};

