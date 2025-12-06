class Solution {
public:
    int rob(vector<int>& a) {
        // we will solve this pb by dep, with O(1 space complexity)
    int n = a.size();
            int prev1 = a[0];
        int prev2 = 0;
        int money = 0;
        for(int i=1;i<n;i++){

            int rob = a[i];
            if(i > 1) rob += prev2;

            int not_rob = prev1;

            money = max(rob,not_rob);
            prev2 = prev1;
            prev1 = money;

        }
        return prev1;
    }
};