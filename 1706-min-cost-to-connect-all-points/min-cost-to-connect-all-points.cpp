class Solution {

    int find_par(int i,vector<int>&par){

        if(par[i] == i)return i;

        return par[i] = find_par(par[i],par);

    }

    void union_y_size(int u,int v,vector<int>&par,vector<int>&size){

        int pu = find_par(u,par);
        int pv = find_par(v,par);

        if(pu == pv)return;

        if(size[pu] < size[pv]){
            par[pu] = pv;
            size[pv] += size[pu]; 
        }else{
            par[pv ] = pu;
            size[pu] += size[pv];
        }
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<pair<int,pair<int,int>>> arr;
        int n = points.size();
        
        vector<int> vis(n,0),size(n,1);
        for(int i=0;i<n;i++){
            auto vec = points[i];
            int x1 = vec[0],y1 = vec[1];
            for(int j = i+1;j<n;j++){
                auto vec = points[j];
                int x2 =vec[0],y2 = vec[1];
                int dist = abs(x1-x2) + abs(y1-y2);

                arr.push_back({dist,{i,j}});
            }
        }

        sort(arr.begin(),arr.end());


        long long ans = 0;
        vector<int> par(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }

       
        for(auto vec : arr){

            int dist  = vec.first,i = vec.second.first,j = vec.second.second;

            if(find_par(i,par) != find_par(j,par)){
                 ans += dist;
              
                 union_y_size(i,j,par,size);

              

            }
        }

        return (int)ans;



    }
};