// recursion  ->>>>>>>>>>>>>>>>>>>>
class Solution {
    int mx = 0,n1,n2,cnt = 0;
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>&a1,vector<int>&a2){

        if( i>= n1 || j >= n2){
            return 0;
        }

        int match = 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(a1[i] == a2[j]){
          
            match = 1 + solve(i+1,j+1,a1,a2);
        }else{
            return 0;
        }
        
       return dp[i][j] = match;
        
    }

public:
    int findLength(vector<int>& a1, vector<int>& a2) {
        n1 = a1.size(),n2 = a2.size();
        dp.assign(n1,vector<int>(n2,-1));
        for(int i=0;i<n1;i++){
            for(int j = 0;j < n2;j++){
                
                mx = max(mx,solve(i,j,a1,a2));
               
            }
        }
         
        return mx;
    }
};





/// Brute forces approach  ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// class Solution {
// public:
//     int findLength(vector<int>& a1, vector<int>& a2) {
        
//         int mx = 0,cnt = 0;
//         for(int i=0;i<a1.size();i++){
//             for(int j = 0;j<a2.size();j++){
//                 if(a1[i] == a2[j]){
//                     cnt = 0;
//                     int l = i,r = j;
//                     while(l < a1.size() && r < a2.size()){
//                         if(a1[l] == a2[r])cnt++;
//                         else break;
//                         mx = max(mx,cnt);
//                         l++,r++;
//                     }
                    
//                 }
//             }
//             if(mx == a1.size() || mx == a2.size())break;
//         }
//         return mx;
//     }
// };
