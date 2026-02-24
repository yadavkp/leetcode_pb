class Solution {
    #define vi vector<int>
    #define pb push_back


    int findpar(int nod,vi&par){

        if(par[nod] == nod)return nod;

        return par[nod] = findpar(par[nod],par);
    }

    void union_y_size(int u,int v, vi&par,vi&size){

        int pu = findpar(u,par);
        int pv = findpar(v,par);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            par[pu] = pv;
            size[pv]+=size[pu];
        }else{
            par[pv] = pu;
            size[pu]+=size[pv];
        }

    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        vi par(n);
        vi size(n,1);
        for(int i=0;i<n;i++) par[i] = i;

        unordered_map<string,int> em_idx;

        for(int i=0;i<n;i++){

            for(int j = 1;j<accounts[i].size();j++){
                string email = accounts[i][j];

                if(em_idx.count(email)){
                    union_y_size(i,em_idx[email],par,size);
                }else{
                    em_idx[email] = i;
                }
            }
        }

        unordered_map<int,vector<string>> merg_grp;

        for(auto const&[email,idx] : em_idx){
            int leader = findpar(idx,par);
            merg_grp[leader].pb(email);
        }

        vector<vector<string>> res;

        for(auto [idx,email] : merg_grp){
            sort(email.begin(),email.end());

            vector<string> row;
            row.pb(accounts[idx][0]);//
            // row.insert(row.end(),email.begin(),email.end());
            for(auto em : email){
                row.pb(em);
            }

            res.pb(row);
        }

        return res;
    }
};