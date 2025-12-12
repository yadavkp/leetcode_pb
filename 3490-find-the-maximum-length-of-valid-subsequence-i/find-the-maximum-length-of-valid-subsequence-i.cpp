class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if(n==2){
            return 2;
        }
        int ev = 0,od = 0;
        for(auto t  :nums){
            if(t%2)od++;
            else ev++;
        }

        int mx = 1;
        int turn = (nums[0]%2==0 ? 0 : 1);
        turn = !turn;
        for(int i=1;i<n;i++){
            if(turn == nums[i]%2){
                mx++;
                turn = !turn;
            }
        }
        return max({od,ev,mx});
    }
};