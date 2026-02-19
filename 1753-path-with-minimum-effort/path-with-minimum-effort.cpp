class Solution {
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
public:
    int minimumEffortPath(vector<vector<int>>& hight) {
        
        int n = hight.size() , m = hight[0].size();

        priority_queue< vector<int>, vector<vector<int>> ,greater<vector<int>> > pq;

        pq.push({0,0,0});

        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));

        dist[0][0] = 1;
        while(!pq.empty()){
             auto vec = pq.top() ; pq.pop();

             int old_dist = vec[0],r = vec[1],c = vec[2];
           
             if(r == n-1 && c == m-1){
                return old_dist;
             }

             for(int i=0;i<4;i++){
                int n_r = r + dx[i];
                int n_c = c + dy[i];

                if(n_r >= 0 && n_r < n && n_c >= 0 && n_c < m ){

                    int new_dist = abs(hight[r][c] - hight[n_r][n_c]);

                    new_dist = max(new_dist,old_dist);
                    
                    if(new_dist < dist[n_r][n_c]){
                        dist[n_r][n_c] = new_dist;
                        pq.push({new_dist,n_r,n_c});
                    }
                   
                }
             }
        }

        return 0;
    }
};



// class Solution {

//     int dx[4] = {0,0,-1,1};
//     int dy[4] = {-1,1,0,0};
//     int n,m;

// #define vvi vector<vector<int>> 
    
// bool dfs(int r,int c,int tar, vvi&vis,vvi&grid){

//         vis[r][c] = 1;

//         if(r == n-1 && c == m-1){
//             return true;
//         }

//         for(int i=0;i<4;i++){

//             int n_r = r + dx[i];
//             int n_c = c + dy[i];

//             if(n_r >= 0 && n_r < n && n_c >= 0 && n_c < m && vis[n_r][n_c] == 0){
//                if(abs(grid[r][c] - grid[n_r][n_c]) <= tar){
//                     if(dfs(n_r,n_c,tar, vis,grid)){
//                               return true;
//                     }
//                }
//             }
//         }

//         return false;
//     }


// public:
//     int minimumEffortPath(vector<vector<int>>& grid) {
        
//         n = grid.size(),m = grid[0].size();
//         int l = 0,h = 1e9;
//         int ans = 1e9;
//         while(l <= h){

//             int mid = l + (h - l) /2 ;
//             vector<vector<int>> vis(n,vector<int>(m,0));
//             if(dfs(0,0,mid,vis,grid)){
                
//                 ans = mid;
//                 h  = mid -1;
//             }else{
//                l = mid + 1;
//             }
//         }
//         return ans;
//     }
// };

