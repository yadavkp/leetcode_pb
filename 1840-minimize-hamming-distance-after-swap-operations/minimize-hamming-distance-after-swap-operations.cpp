class Solution {
    int n;
    vector<int> par,size;

    int find_par(int u){

        if(par[u] == u) return u;

        return par[u] = find_par(par[u]);
    }

    void union_y_size(int u,int v){

        int pu = find_par(u);
        int pv = find_par(v);

        if(pu == pv) return ;

        if(size[pu] < size[pv]){
            swap(pu,pv);
        }

        par[pv] = pu;
        size[pu] += size[pv];
    }
public:
    int minimumHammingDistance(vector<int>& src, vector<int>& tar, vector<vector<int>>& swp) {


        n = src.size();
        par.assign(n,0);
        size.assign(n,1);
        for(int i=0;i<n;i++){
            par[i] =  i;
        }

        for(auto vec : swp){
            int u =  vec[0],v = vec[1];
            if(find_par(u) != find_par(v)){

                union_y_size(u,v);
            }
        }

       
        int dist  =0;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            adj[find_par(i)].push_back(i);
        }

        for(auto vec : adj){
            multiset<int> m1,m2;
            for(auto idx : vec){
                m1.insert(src[idx]);
                m2.insert(tar[idx]);
            }

            for(auto val : m1){
                if(m2.count(val)){
                    auto it = m2.find(val);
                    m2.erase(it);
                }
            }
            dist += m2.size();
        }

        return dist;
    }
};