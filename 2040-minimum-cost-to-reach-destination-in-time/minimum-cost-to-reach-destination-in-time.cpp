class Solution {
    #define pb push_back
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto vec : edges){
            int u  = vec[0], v = vec[1], w = vec[2];
            adj[u].pb({w,v});
            adj[v].pb({w,u});
        }
        
        using  T = tuple<int,int,int>; 
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({passingFees[0], 0, 0}); // old_fees, curr_time, u

        vector<vector<int>> dist(n, vector<int>(maxTime+1, 1e9));
        dist[0][0] = passingFees[0];

        while(!pq.empty()){
            auto [old_fees, old_time, u] = pq.top();
            pq.pop();

            if(u == n-1){
                return old_fees;
            }

            if(dist[u][old_time] < old_fees) continue; // prune worse states

            for(auto [w,v] : adj[u]){
                if(old_time + w <= maxTime){
                    int new_fees = old_fees + passingFees[v];
                    if(dist[v][old_time + w] > new_fees){
                        dist[v][old_time + w] = new_fees;
                        pq.push({new_fees, old_time + w, v});
                    }
                }
            }
        }

        return -1;
    }
};