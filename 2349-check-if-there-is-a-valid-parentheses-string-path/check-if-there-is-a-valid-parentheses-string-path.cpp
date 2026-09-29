class Solution {
    bool check(vector<vector<char>>& grid){
        int n = grid.size(),m = grid[0].size();
        if(grid[0][0]==')') return false;

        using T = tuple<int,int,int>;

        queue<T> q;

        q.push({0,0,1});
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(201,0)));
        vis[0][0][1]=1;

        while(!q.empty()){

            auto [r,c,d] = q.front(); q.pop();
            
            if(d < 0 )continue;
            if((d == 0) && (r == n-1 && c == m-1)) return true;

            if( (r+1 < n)){ // down 
                int nd=-1;
                if(grid[r+1][c] == ')' && (d -1) >= 0){
                    nd = d-1;
                }else if(grid[r+1][c]=='('){
                    nd = d+1;
                }

                if(nd >= 0 && !vis[r+1][c][nd]){
                    q.push({r+1,c,nd});
                    vis[r+1][c][nd]=1;
                }
            }

            if(c+1 < m){ // right 

               int nd=-1;
                
                if(grid[r][c+1] == ')' && (d - 1) >= 0){
                    nd = d-1;
                }else if(grid[r][c+1]=='('){
                    nd = d+1;
                }

                if(nd >= 0 && !vis[r][c+1][nd]){
                    q.push({r,c+1,nd});
                    vis[r][c+1][nd]=1;
                }
                
            }

        }

        return false;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        
        
        return check(grid);

    }
};