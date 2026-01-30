class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<bool> arr(n,false);
        arr[0] = true;

        for(int i=0;i<n-1;i++){
           if(arr[i]==true){
                for(int j = i;j <= i + nums[i] && j < n;j++){
                    arr[j] = true;
                }
           } 
        }

        
        return (arr[n-1] == true);
    }
};