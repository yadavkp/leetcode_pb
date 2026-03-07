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

        if(pu !=  pv){

            if(size[pu] < size[pv])swap(pu,pv);

            par[pv]  = pu;
            size[pu] += size[pv];
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        par.assign(n+1,0);
        size.assign(n+1,1);
        for(int i = 1;i<=n;i++){
            par[i] = i;
        }

        for(auto vec : edges){
            int u = vec[0],v = vec[1];

            if(find_par(u) == find_par(v)){
                return {u,v};
            }
            union_y_size(u,v);
        }

        return{0,0};
        
    }
};