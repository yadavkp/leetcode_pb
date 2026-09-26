class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        map<string,string> mp;

         for(int i=0;i < knowledge.size();i++){

            auto v = knowledge[i];
            mp[v[0]] = v[1];
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