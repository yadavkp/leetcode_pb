class Solution {

    int extract(int nn){
        int n = nn;
        set<int> ans;
        int sum = 0;
        ans.insert(1);ans.insert(n);

        for(int i=2; i*i <= n;i++ ){

            if(n % i == 0){
                while( n%i==0){
                    ans.insert(n/i);
                     n /= i;
               }
               ans.insert(i);
            }
        }

        if(n > 1) ans.insert(n);

        if(ans.size() == 4){
            for(auto t : ans){
               sum += t;
               
            }
        }

        return sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += extract(nums[i]);
        }
        return ans;
    }
};