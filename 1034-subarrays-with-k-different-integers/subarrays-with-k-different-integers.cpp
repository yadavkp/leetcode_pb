/*
idea->  here we need exactly k , so this calculations in sliding window is inefficient, why-> because we need to maintain lot of left, right pointer
so here we count upto k  then subtract upto k-1, that will give ans exactly k

*/

class Solution {
    private:
        int atmostk(vector<int>&nums,int k){

            unordered_map<int,int> frq;

            int i = 0,j =0,len = 0,n = nums.size();
            while(j < n){
                    frq[nums[j]]++;
                    while(frq.size()>k){
                        frq[nums[i]]--;
                        if(frq[nums[i]]==0){
                            frq.erase(nums[i]);
                        }
                        i++;
                    }
                    if(frq.size()<=k){
                        len += (j - i+1);
                    }
                    j++;
            }
            return len;
        }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
       return atmostk(nums,k) - atmostk(nums,k-1);

    }
};