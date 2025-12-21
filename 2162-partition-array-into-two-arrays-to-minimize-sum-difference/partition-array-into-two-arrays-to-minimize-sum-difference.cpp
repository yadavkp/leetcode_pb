class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<vector<int>> left(n+1),right(n+1);

        // generate all subset only from first n number,
        for(int mask = 0; mask < (1 << n);mask++){
            int left_sum = 0,right_sum = 0;
            int ele = 0;
            for(int i=0;i<n;i++){
                if((mask & (1 << i))){
                    ele++;
                    left_sum += nums[i];
                    right_sum += nums[n+i];
                }
            }
            left[ele].push_back(left_sum);
            right[ele].push_back(right_sum);
        }

        // sort right subset because we will apply here bs
        for(int i=0;i<=n;i++){
            sort(right[i].begin(),right[i].end());
        }

        int tot_sum = accumulate(nums.begin(),nums.end(),0);
        int mn_sum = INT_MAX;
        // check full subsets if they exist
        if (!right[n].empty())
            mn_sum = min(mn_sum, abs(tot_sum - 2 * right[n][0]));
        if (!left[n].empty())
            mn_sum = min(mn_sum, abs(tot_sum - 2 * left[n][0]));

        
        for(int i=1;i<n;i++){
            for(auto &val : left[i]){
                int target = (tot_sum - 2*val)/2;   // this thing i don't understand so far 
                int right_idx = n - i;
                auto &arr = right[right_idx];
                auto lb = lower_bound(arr.begin(),arr.end(),target);
                
                if(lb != arr.end()){
                    mn_sum = min(mn_sum , abs(tot_sum - 2*(val + *lb)));
                }
            }
        }

        return mn_sum;
    }
};