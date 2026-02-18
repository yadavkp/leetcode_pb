class Solution {
    #define ll long long
    #define pb push_back
    ll cnt = 0;
     const int mod  = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<ll,ll>>> adj(n);

        for(auto vec : roads){
            adj[vec[0]].pb({vec[2],vec[1]});
            adj[vec[1]].pb({vec[2],vec[0]});
        }

        vector<ll> dist(n,1e18);
        dist[0] = 0;
        priority_queue< pair<ll,ll> , vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;

        pq.push({0,0});
        vector<ll> ways(n,0);
        ways[0] = 1;
        while(!pq.empty()){

            auto [d,u] = pq.top(); pq.pop();

            if(d > dist[u]) continue;

            for(auto [w,nr] : adj[u]){

                if(dist[nr] > dist[u] + w){
                    dist[nr] = dist[u] + w;
                    ways[nr] = ways[u] % mod;
                    pq.push({dist[nr], nr});
                }else if(dist[nr] == dist[u] + w){
                    ways[nr]  = (ways[nr] +  ways[u]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};