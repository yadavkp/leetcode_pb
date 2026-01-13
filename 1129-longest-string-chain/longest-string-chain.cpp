class Solution {

    vector<vector<int>> dp;
    bool  mischar(string &s1,string &s2){
        if(s1.size() != s2.size()+1)return false;
        // s1 is the frist string,and s2 is the prev string
        int i=0,j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                i++,j++;
            }else{
                i++;
            }
        }
        return j == s2.size();
    }

    int solve(int i,int p_idx, vector<string>& words){

        if(i >= words.size()) return 0;

        int not_take = solve(i+1,p_idx,words);
        int take = 0;

        if(dp[i][p_idx+1] !=-1)return dp[i][p_idx+1];

        if(p_idx == -1 || mischar(words[i], words[p_idx])){
            take = 1 + solve(i+1,i,words);
        }
        

        return  dp[i][p_idx+1] =  max(take,not_take);
    }

public:
    int longestStrChain(vector<string>& words) {
       
        auto cmp = [&](const string &s1,const string &s2){
            return s1.size() < s2.size();
        };

        sort(words.begin(),words.end(),cmp);

        // for(auto s : words){
        //     cout<<s<<" ";
        // }
        int n = words.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        int ans = solve(0,-1,words);

         return ans;
    }
};