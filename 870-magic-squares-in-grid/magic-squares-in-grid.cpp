class Solution {

     bool isMagic(vector<vector<int>>& mat){
        // all numbers must be 1-9 and distinct
        vector<int> seen(10, 0);
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                int val = mat[r][c];
                if(val < 1 || val > 9 || seen[val]) return false;
                seen[val] = 1;
            }
        }
        
        // each row, col, diag must sum to 15
        int sumRow0 = mat[0][0] + mat[0][1] + mat[0][2];
        int sumRow1 = mat[1][0] + mat[1][1] + mat[1][2];
        int sumRow2 = mat[2][0] + mat[2][1] + mat[2][2];
        
        int sumCol0 = mat[0][0] + mat[1][0] + mat[2][0];
        int sumCol1 = mat[0][1] + mat[1][1] + mat[2][1];
        int sumCol2 = mat[0][2] + mat[1][2] + mat[2][2];
        
        int sumDiag1 = mat[0][0] + mat[1][1] + mat[2][2];
        int sumDiag2 = mat[0][2] + mat[1][1] + mat[2][0];
        
        return (sumRow0 == 15 && sumRow1 == 15 && sumRow2 == 15 &&
                sumCol0 == 15 && sumCol1 == 15 && sumCol2 == 15 &&
                sumDiag1 == 15 && sumDiag2 == 15);
    }


public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int cnt = 0;
        
        int n = grid.size(), m = grid[0].size();
        if(n > 2 && m > 2){
            for(int i = 0; i < n - 2; i++){
                for(int j = 0; j < m - 2; j++){
                    
                    // collect the 3x3 subgrid
                    vector<vector<int>> mat(3, vector<int>(3));
                    for(int row = 0; row < 3; row++){
                        for(int col = 0; col < 3; col++){
                            mat[row][col] = grid[i + row][j + col];
                        }
                    }
                    if(isMagic(mat)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
    
   
};