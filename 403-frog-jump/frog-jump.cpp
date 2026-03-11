// class Solution {

//     bool solve(int i,int jump,vector<int>&stones){

//         if(i == stones.size()-1) return true;


//         bool ans = false;
//         for(int idx = i + 1;idx < stones.size();idx++){

            
//             for(int k = -1;k < 2;k++){
              
//                 if(stones[idx] - stones[i] == jump + k){
//                     ans |= solve(idx,jump + k, stones);
//                 }
//             }
//         }

//         return ans;
//     }

// public:
//     bool canCross(vector<int>& stones) {

//        if(stones[1]-stones[0] > 1) return false;

//        return solve(0,1,stones);
//     }
// };


class Solution {
    
public:
    bool canCross(vector<int>& stones) {

        unordered_map<int,unordered_set<int>> seen;

        seen[stones[0] + 1] = {1};

        for(int i=1;i<stones.size();i++){
            int pos = stones[i];

            for(auto it : seen[pos]){

                seen[pos + it] .insert(it); // k
                seen[pos + it+1] .insert(it+1); // k+1
                seen[pos + it - 1] .insert(it-1); // k-1;
            }
        }

        return seen[stones[stones.size()-1]].size() != 0;
      
    }
};