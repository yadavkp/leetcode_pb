class Solution {

    struct state {
        long long  score;
        vector<int> idx;
    };
    vector<int> nxt;

    state solve(vector<vector<int>>&ivl,int i,int k,vector<vector<state>>&dp,vector<vector<int>>&vis){

        int n = ivl.size();

        if(i == n || k == 0){
            return {0,{}};
        }

        if(vis[i][k]) return dp[i][k];

        vis[i][k] = 1;

        state not_take = solve(ivl,i+1,k,dp,vis);

        state take = solve(ivl,nxt[i],k-1,dp,vis);

        take.score += ivl[i][2];

        take.idx.push_back(ivl[i][3]);

        sort(take.idx.begin(),take.idx.end());

        if(take.score > not_take.score){
            return dp[i][k] = take;
        }
        if(take.score < not_take.score){
            return dp[i][k] = not_take;
        }
        if(take.idx < not_take.idx) return dp[i][k] = take;

        return dp[i][k] = not_take;
    }
public:
    vector<int> maximumWeight(vector<vector<int>>& ivl) {
        int n = ivl.size();

        for(int i=0;i < n;i++){
            ivl[i].push_back(i);
        }
        sort(ivl.begin(),ivl.end());
        nxt.assign(n,0);
        for(int i=0;i < n;i++){
                int lo = i+1,hi = n;

                while(lo < hi){
                    int mid = lo + (hi - lo) / 2;

                    if(ivl[mid][0] > ivl[i][1]){
                        hi = mid;
                    }else{
                        lo = mid+1;
                    }
                }
                nxt[i] = lo;
        }
        

        vector<vector<state>> dp(n+1,vector<state>(5));
        vector<vector<int>> vis(n+1, vector<int>(5,0));

        state ans = solve(ivl,0,4,dp,vis);

        return ans.idx;  // ans ka idx part 
    }
};