
class Solution {
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>> > pq;


        pq.push({0,0,0,k}); // steps,r,c,k


        vis[0][0] = k;

        auto valid = [&](int r,int c){

            if(r  < 0 || r >= n || c <0 || c >= m ) return false;

            return true;

        };

        while(!pq.empty()){

            auto vec = pq.top() ;  pq.pop();
            int steps = vec[0];
            int r = vec[1];
            int c = vec[2];
            int rem_k = vec[3];

                if(r == n-1 && c == m-1){
                    return steps;
                }
              

                for(int i=0;i<4;i++){

                    int n_r = r + dx[i];
                    int n_c = c + dy[i];
                    
                    if(valid(n_r,n_c)){

                        int next_k = rem_k - grid[n_r][n_c];

                        if(next_k >= 0 && next_k > vis[n_r][n_c]){  // 0 > -1
                            vis[n_r][n_c] = next_k;
                            pq.push({steps+1,n_r , n_c , next_k});
                        }
                       
                    }
                }
            }
           
        
        return -1;
    }
};