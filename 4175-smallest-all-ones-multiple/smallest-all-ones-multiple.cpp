class Solution {
public:
    int minAllOneMultiple(int k) {
        unordered_set<int> seen;

        int rem = 1;int cnt = 1;
        seen.insert(rem);
        while(rem%k != 0){

            int val = (rem*10 + 1)%k;
              rem = val%k;
              cnt++;
            if(seen.count(rem)){
                return -1;
            }
            seen.insert(rem);
            
        }
        return cnt;
    }
};