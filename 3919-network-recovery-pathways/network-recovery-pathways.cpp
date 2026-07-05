class Solution {
    int n;
    #define ll long long
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();

        vector<vector<pair<int,int>>> adj(n);
         vector<int> wt; // disticnt weight arr me dalo, aur apply binary search
        
        for(auto &e : edges){
            int u  = e[0],v = e[1],w = e[2];
            adj[u].push_back({v,w});
            wt.push_back(w);
        }
        

        sort(wt.begin(),wt.end());
        wt.erase(unique(wt.begin(),wt.end()),wt.end());

        /*
        // here will run the lamda function ;;
        */

        auto valid = [&](int mid)  {
            vector<ll> dist(n,1e18);
            dist[0] = 0;
            priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<> > pq;
            pq.push({0,0});

            while(!pq.empty()){
                auto [d,u] = pq.top();pq.pop();

                if(d > dist[u])continue;
                
                for(auto [v,w] : adj[u]){

                    if(w < mid) continue;
                    if(v != n-1 && !online[v])continue;
                    ll nd = d + w;
                    if(nd < dist[v]){
                        dist[v] = nd;
                        pq.push({nd,v});
                    }
                }
                
            }
            return dist[n-1] <= k;
        };

        int lo = 0,hi = (int)wt.size()-1,ans = -1;
       
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(valid(wt[mid])){
                ans = wt[mid];
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
};