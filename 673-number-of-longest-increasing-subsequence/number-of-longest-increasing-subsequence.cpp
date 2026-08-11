class Solution {
    
    vector<vector<pair<int,int>>> dp;
    int n;

    pair<int,int> solve(int i,int prev, vector<int>&a){

        if(i >= n) return {0,1};

        if(dp[i][prev+1].first != -1 ) return dp[i][prev+1];

        pair not_take = solve(i+1,prev,a);

        pair<int,int>take =  {-1e8,0};

        if(prev == -1 || a[prev] < a[i]){
            take =  solve(i+1, i,a);
            take.first = 1 + take.first;
        }

        if(take.first > not_take.first){
           return  dp[i][prev+1] = take;
        }else if(take.first < not_take.first){
           return  dp[i][prev+1] = not_take;
        }else{

            return  dp[i][prev+1] = {take.first, take.second + not_take.second};
        }

       
    }
    
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        // lets find the first lis, then again use that length , and apply
        // that those have the same length, increase the count 
        n = nums.size();
        dp.assign(n,vector<pair<int,int>>(n+1,{-1,-1}));
    

        pair<int,int> res = solve(0,-1,nums);

        return res.second;

    }
};