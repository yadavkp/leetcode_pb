class Solution {
    vector<int> par,size;

    int find_par(int u){

        if(par[u] == u) return u;
        return par[u]  = find_par(par[u]);
    }

    void union_y_size(int u,int v){

        int pu = find_par(u);
        int pv = find_par(v);

        if(pu != pv){
            if(size[pu] < size[pv])swap(pu,pv);

            par[pv] = pu;
            size[pu] += size[pv];
        }
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& qry) {
        
        par.assign(n,0);
        size.assign(n,1);
        for(int i=0;i<n;i++){
            par[i] = i;
        }

        for(int i=0;i<n-1;i++){

            if(abs(nums[i] - nums[i+1]) <= maxDiff){
                union_y_size(i,i+1);
            }
        }


         int q = qry.size();
        vector<bool> ans(q,0);


       
        for(int i=0;i<q;i++){
            int u = qry[i][0];
            int v = qry[i][1];

            if(find_par(u) == find_par(v)){
                ans[i] = 1;
            }
        }

        return ans;

    }
};