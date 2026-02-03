class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n = nums.size();

        if(n <= 3)return false;

        int i=1,j = 0,k = 0;
        
        while(i < n-2 && nums[i-1] < nums[i])i++;

        if(i == 1)return false;
       
        j = i;
        while(j < n-1 && nums[j-1] > nums[j])j++;

        if(j == i) return false;

        k = j;
    
        while(k < n  && nums[k-1] < nums[k])k++;

        return k == n;
    }
};