class Solution {
    int n,m;
    int mn = 1e9,mx = 0;
    vector<int> ans;
    int check(vector<vector<int>>& grid,int x){

        int mod = grid[0][0] %x;
        int found = 1;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]%x != mod) found = 0;
                ans.push_back(grid[i][j]);
            }
        }
        return found;
    
    }

    

public:
    int minOperations(vector<vector<int>>& grid, int x) {
        n = grid.size(),m = grid[0].size();

        if(check(grid,x)==0) return -1;
        sort(ans.begin(),ans.end());

        int mid = 0;
        int mod = ans[0] % x;
        n = ans.size();
        if(n&1) mid = ans[n/2];
        else {
            mid = ans[n/2];
        }

        int low = mid - (mid%x) + mod;  // mod aware ✅
        if(low > mid) low -= x;         // overshoot fix ✅
        int high = low + x;

        int op1=0,op2 = 0;

        for(int i=0;i<n;i++){
            op1 += (abs(low - ans[i]) / x);
            op2 += (abs(high - ans[i]) / x);
        }

        return min(op1,op2);
        
    }
};