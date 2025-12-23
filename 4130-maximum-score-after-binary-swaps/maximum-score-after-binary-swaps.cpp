class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long score = 0;

        int i = 0,n = s.size();
        priority_queue<long long> pq;
        while(i < n){
            pq.push(nums[i]);
            if(s[i]=='1'){
                score += pq.top();
                pq.pop();
            }
            i++;
        }

        return score;
    }
};