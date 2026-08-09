class Solution {
    int n,m;
    vector<vector<int>> pfx;

    bool valid(int k){


        int found = 0;
        int mn_row = INT_MAX,mn_col = INT_MAX;
        int mx_row = INT_MIN, mx_col = INT_MIN;

        for(int r = 0; r + k <= n; r++){
            for(int c = 0; c + k <= m; c++){

                int sum = pfx[r+k][c+k] - pfx[r+k][c] - pfx[r][c+k] + pfx[r][c];
                if(sum == k*k){
                    
                    found = 1;

                    mn_row = min(mn_row,r),mx_row = max(mx_row,r);
                    mn_col = min(mn_col,c), mx_col = max(mx_col,c);
                }
            }
        }

        if(!found) return false;

        if((mx_row - mn_row) >= k || (mx_col - mn_col >= k) ) return true;

        return false;
    }
public:
    int maxArea(vector<vector<int>>& mat) {

        n = mat.size(),m = mat[0].size();
        int cnt = 0;
       pfx.assign(n+1,vector<int>(m+1,0));
        for(int i=0; i < n ; i++){
            for(int j = 0;  j < m; j++){
                    int r = i+1,c = j+1;
                if(mat[i][j])cnt++;
                pfx[r][c] = mat[i][j] + pfx[r][c-1] + pfx[r-1][c] - pfx[i][j];
              
            }
            cout<<"\n";
        }


       

        int ans = 0;
        
        int l = 0, h = min(n,m);

        while(l <= h){

            int k = l + (h - l ) /2;

            if(valid(k)){
                ans = k;
                l = k+1;
            }else{
                h = k-1;
            }
        }

        

        return ans * ans;

        

        
    }
};