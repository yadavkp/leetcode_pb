class Solution {
    // simple bfs use here to reach to that position 
public:
    bool canReach(vector<int>& nums, int start) {
        
        queue<int> q;
        q.push(start);
        int n = nums.size();
        vector<int> vis(n,0);
        vis[start] = 1;
        while(!q.empty()){

            auto idx  = q.front();q.pop();

            if(nums[idx] == 0) return true;

            if( idx-nums[idx] >= 0 && !vis[idx-nums[idx]]){
                q.push(idx-nums[idx]);
                vis[idx-nums[idx]]=1;
            }
            if(idx + nums[idx] < n && !vis[idx+nums[idx]]){
                q.push( idx + nums[idx]);
                vis[idx + nums[idx]]=1;
            }
        }

        return false;
    }
};