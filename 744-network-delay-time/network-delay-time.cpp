class Solution {
    #define ll long long 
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>> > adj(n);

        for(int i=0;i<(int)times.size();i++){

            int u = times[i][0],v = times[i][1],w = times[i][2];
            u--,v--;
            adj[u].push_back({w,v});
            
        }


        vector<ll> dist(n,1e18);

    priority_queue< pair<ll,ll> , vector<pair<ll , ll>> , greater<pair<ll, ll >> > pq;


    k--;
    dist[k] = 0;
    pq.push({0,k});


    while(!pq.empty()){

        auto [d,u] = pq.top();
        pq.pop();

        for(auto [w,v] : adj[u]){

            if(dist[v] > dist[u] + w){

                dist[v] = dist[u] + w;
                
                pq.emplace(dist[v], v);

               
            }
        }
    }

    ll mx = 0;
    for(int i=0;i<n;i++){

        mx = max(mx,dist[i]);

         if(mx == 1e18) return -1;
        
    }

    return mx;

    



    }
};