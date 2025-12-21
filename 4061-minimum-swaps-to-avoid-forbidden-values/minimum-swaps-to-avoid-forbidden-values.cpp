class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& fbdn) {
        int ops = 0;
        int n = nums.size();
        // c-1 >  when ans will be the -1; frq[val] >= (n+1)

        // c-2 > when ans will be the 0; , no equal pair found
        // c-3 >  when ans = no of operations; // other count

        unordered_map<int,int> frq;
         unordered_map<int,int> bad_frq;
        int mx_frq = 0;
        vector<pair<int,int>> badpairs;
        int mx_bd_frq = 0;  // mx_bad pair frq 
        for(int i=0;i<n;i++){
            frq[nums[i]]++;
            frq[fbdn[i]]++;

            mx_frq = max({mx_frq,frq[nums[i]],frq[fbdn[i]]}); // count mx frq-> that will comes on both arrays

            if(nums[i] == fbdn[i]){
                badpairs.push_back({nums[i],fbdn[i]});
                bad_frq[nums[i]]++;
                mx_bd_frq = max(mx_bd_frq,bad_frq[nums[i]]);
            }
        }

        if(mx_frq >= (n+1))return -1;
        else if(badpairs.size()==0)return 0;
        else{
            return max((int)(badpairs.size()+1)/2,mx_bd_frq);
        }
    }
};