// //  for this pb, simple build the manually think grid  , that have exact k path // rather than building the backtracking o(r dp to count the path it lead to exponentially time complexity) 

// class Solution{
//     vector<vector<char>> grid;
//     vector<string> ans;
//     int m,n,k;
//     int found = 0;

//     int r = 0,c = 0;

//     void solve(){

//         if(k == 1){
//             found = 1;
//             r = 0,c = 0;
//         }else if(k == 2){
//             if(m >=2 && n >= 2){
//                 found = 1;
//                 r = 1,c = 1;
//             }

//         }else if(k == 3){
//             if( m >= 2  && n >= 3){
//                 found =1;
//                 r = 1,c = 2;
//             }else if(m >= 3 && n>=2){
//                 found = 1;
//                 r = 2,c = 1;
//             }

//         }else if(k == 4){
//             if(m >= 2 && n >= 4){
//                 r = 1,c = 3;
//                 found = 1;
//             }else if( m >= 4 && n >= 2){
//                 found = 1;
//                 r = 3,c = 1;
//             }else if((m >= 3 && n >= 3)){
//                 found = 2;
//                 r = 2,c = 2;
//             }
//         }

//         if(found){
//                 for(int i=0; i < m; i++){
//                     for(int j = 0; j < n; j++){
//                         if(i <=r && j <= c)continue;
//                         grid[i][j] = '#';
//                     }

//                 }
//         }
//     }


// public:
//     vector<string> createGrid(int mm, int nn, int kk) {
//         m = mm,n = nn,k=kk;
        
//         ans.clear();
//         grid.assign(m,vector<char>(n,'.'));
        
//         found = 0;
//         solve(); // lets find the center of min cell got exact k path, and possibility to make path or not

//         if(m >=3 && n >= 3 && r == 2 && c == 2){
//                 grid[0][2] = '#',grid[2][0] = '#';
//         }

//         if(found){
//             // first mark  3 y 3 , bc
        
//             if(r+1 < m ){  // it means first go bottom, then right
//                 for(int i = r;i < m; i++){
//                     grid[i][c] = '.';
//                 }
//                 for(int j = c;j < n; j++){
//                     grid[m-1][j] = '.';
//                 }
//             } else if(c+1 < n) { // it means first go right , then bottom
//                 for(int j = c;j < n; j++){
//                     grid[r][j] = '.';
//                 }
//                 for(int i = r;i < m; i++){
//                     grid[i][n-1] = '.';
//                 }
               
//             }

//         }

//         if(found){
//                 for(int i=0; i < m; i++){
//                         string s = "";
//                         for(int j = 0; j < n; j++){
//                            s += grid[i][j];
//                         }
//                         ans.push_back(s);

//                 }
//         }

//         return ans;

//     }
// };


class Solution {

    const int static N = 12;
    int dp[N][N];
    vector<vector<char>> grid;
    vector<string> ans;
    int m,n,k;
    int found = 0;

    int check(){

    //     if(i >= m || j >= n) return 0;

    //     if(grid[i][j]  == '#') return 0;

    //     if(i == m-1 && j == n-1){
    //         return 1;
    //     }

    //     if(dp[i][j] != -1) return dp[i][j];

    //     //int right = 0,down = 0;

    //     int right = check(i,j+1);
    //     int down = check(i+1,j);

    //    return  dp[i][j] = right + down;

       memset(dp,0,sizeof(dp));

        dp[m-1][n-1] = 1;
       for(int i = m-1;i >=0 ;i--){
            for(int j = n-1; j >= 0; j--){

               if(grid[i][j] != '#'){

                    if(i != m-1 && j != n-1){
                        dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    }
                   if(i == m-1 && j != n-1){
                     dp[i][j] = dp[i][j+1];
                   }else if(i != m-1 && j == n-1)dp[i][j] = dp[i+1][j];
                
               }else{

               }
            }
       }

       return dp[0][0];

    }

    bool  backtrack(int pos){

        if(check() == k){
            return true;
        }

        if(check() < k) return false;


        if(pos == n*m){
            return false ;
        }

        int r = pos / n, c = pos % n;

        grid[r][c] = '#';
        if( backtrack(pos+1)) return true;

        grid[r][c] = '.';
        if( backtrack(pos+1)) return true;

        return false;

    }
public:
    vector<string> createGrid(int mm, int nn, int kk) {
        m = mm,n = nn,k=kk;
        
        ans.clear();
        grid.assign(m,vector<char>(n,'.'));
        
        
        if(backtrack(0)){
            for(int i=0;i<m; i++){
                string s  ="";
                for(int j = 0; j < n; j++){
                    s += grid[i][j];
                }
                ans.push_back(s);
            }
        }

        return ans;

    }
};

