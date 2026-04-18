class Solution {
    int dp[50005];

    int solve(int i,vector<vector<int>>&job, vector<int>&start){

        if(i >= start.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int not_take = solve(i+1,job,start);
        
        int next_idx = lower_bound(start.begin(),start.end(),job[i][1]) - start.begin();
        int take = job[i][2] + solve(next_idx,job,start);
        
        return dp[i] =  max(take,not_take);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        int n = profit.size();
        vector<vector<int>> sorted;
        for(int i=0;i<n;i++){
            sorted.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(sorted.begin(),sorted.end());
        

        vector<int> start;
        for(auto&vec : sorted){
            start.push_back(vec[0]);
        }

        return solve(0,sorted,start);
    }
};




// class Solution {
//     int dp[50005]; // Size badha diya

//     // Yahan & lagana sabse zaroori hai
//     int solve(int i, vector<vector<int>>& job, vector<int>& start) {

//         if(i >= start.size()) return 0;

//         if(dp[i] != -1) return dp[i];
        
//         // 1. NOT TAKE
//         int not_take = solve(i+1, job, start);
        
//         // 2. TAKE
//         // lower_bound fast jump maarta hai
//         int next_idx = lower_bound(start.begin(), start.end(), job[i][1]) - start.begin();
//         int take = job[i][2] + solve(next_idx, job, start);
        
//         return dp[i] = max(take, not_take);
//     }
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         memset(dp, -1, sizeof(dp));
//         int n = profit.size();
        
//         vector<vector<int>> sorted;
//         for(int i=0; i<n; i++){
//             sorted.push_back({startTime[i], endTime[i], profit[i]});
//         }

//         // Sorting zaroori hai taaki BS kaam kare
//         sort(sorted.begin(), sorted.end());

//         vector<int> start;
//         for(auto& vec : sorted){
//             start.push_back(vec[0]);
//         }

//         return solve(0, sorted, start);
//     }
// };