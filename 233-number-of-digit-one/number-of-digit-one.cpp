class Solution {
    vector<int> a;
    int dp[11][2][10]; // how 10 one hoge ??

    int solve(int idx,int tight,int cnt_1){

        if(idx == a.size()) return cnt_1 ;
        int limit = tight ? a[idx] : 9;
        int res = 0;

        if(dp[idx][tight][cnt_1] != -1) return dp[idx][tight][cnt_1];
        for(int dig=0;dig <= limit;dig++){

           int new_cnt_1 = cnt_1 + (dig == 1);
            int new_tight = tight && (dig == a[idx]);

           res +=  solve(idx+1,new_tight,new_cnt_1);
        }
        return dp[idx][tight][cnt_1] =  res;

    }

public:
    int countDigitOne(int n) {
        

        if(n <= 0) return 0;
        while(n > 0){
            a.push_back(n%10);
            n /= 10;
        }
        memset(dp,-1,sizeof(dp));
        reverse(a.begin(),a.end());
        return  solve(0,1,0);
      
    }
};