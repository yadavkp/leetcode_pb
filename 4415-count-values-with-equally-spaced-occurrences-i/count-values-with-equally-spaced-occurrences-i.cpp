class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        int n = nums.size();

        set<int> seen; // these values i used;
        int cnt = 0;
        for(int i=0;i < n;i++){
            vector<int> idx;
            idx.push_back(i);
            if(!seen.count(nums[i])){
                for(int j = i+1;j < n;j++){
                        if(nums[i] == nums[j]){
                            idx.push_back(j);
                        }
                }
            }

            if(idx.size() == 3){
                if(idx[1] - idx[0] == idx[2] - idx[1])cnt++;
            }
            seen.insert(nums[i]);
        }

        return cnt;
    }
};