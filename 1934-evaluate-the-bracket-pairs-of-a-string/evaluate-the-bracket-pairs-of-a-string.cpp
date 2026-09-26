class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string,string> mp;

         for(auto v1 : knowledge){
            mp[v1[0]] = v1[1];
         }
        int n = s.size();

    string ans = "";
    string temp = "";
      for(int i=0;i < s.size();i++){
             temp = "";
            int j = i+1;
            if(s[i] =='('){
                while(j < n && s[j] != ')'){
                    temp += s[j];
                    j++;
                }
                
                if(!temp.empty() && mp.count(temp)){
                    ans += mp[temp];
                }else{
                    ans += '?';
                }
                temp.clear();
                i = j;

            }else{
                ans +=s[i];
            }
      }
      return ans;
    }
};