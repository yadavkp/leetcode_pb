//  for this pb, simple build the manually think grid  , that have exact k path // rather than building the backtracking o(r dp to count the path it lead to exponentially time complexity) 

class Solution{
    vector<vector<char>> grid;
    vector<string> ans;
    int m,n,k;
    int found = 0;

    int r = 0,c = 0;

    void solve(){

        if(k == 1){
            found = 1;
            r = 0,c = 0;
        }else if(k == 2){
            if(m >=2 && n >= 2){
                found = 1;
                r = 1,c = 1;
            }

        }else if(k == 3){
            if( m >= 2  && n >= 3){
                found =1;
                r = 1,c = 2;
            }else if(m >= 3 && n>=2){
                found = 1;
                r = 2,c = 1;
            }

        }else if(k == 4){
            if(m >= 2 && n >= 4){
                r = 1,c = 3;
                found = 1;
            }else if( m >= 4 && n >= 2){
                found = 1;
                r = 3,c = 1;
            }else if((m >= 3 && n >= 3)){
                found = 2;
                r = 2,c = 2;
            }
        }

        if(found){
                for(int i=0; i < m; i++){
                    for(int j = 0; j < n; j++){
                        if(i <=r && j <= c)continue;
                        grid[i][j] = '#';
                    }

                }
        }
    }


public:
    vector<string> createGrid(int mm, int nn, int kk) {
        m = mm,n = nn,k=kk;
        
        ans.clear();
        grid.assign(m,vector<char>(n,'.'));
        
        found = 0;
        solve();

        if(m >=3 && n >= 3 && r == 2 && c == 2){
                grid[0][2] = '#',grid[2][0] = '#';
        }

        if(found){
            // first mark  3 y 3 , bc
            

            if(r+1 < m ){  // it means first go bottom, then right
                for(int i = r;i < m; i++){
                    grid[i][c] = '.';
                }
                for(int j = c;j < n; j++){
                    grid[m-1][j] = '.';
                }
            } else if(c+1 < n) { // it means first go right , then bottom
                for(int j = c;j < n; j++){
                    grid[r][j] = '.';
                }
                for(int i = r;i < m; i++){
                    grid[i][n-1] = '.';
                }
               
            }

        }

        if(found){
                 for(int i=0; i < m; i++){
                    string s = "";
                        for(int j = 0; j < n; j++){
                           s += grid[i][j];
                        }
                        ans.push_back(s);

                    }
        }

        return ans;

    }
};