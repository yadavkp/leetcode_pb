class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        
        int n = s.size();

        vector<bool> ans;
        vector<int> pfx(n+1,0);
        for(int i=0;i<n;i++){
            pfx[i+1] = pfx[i] + ((s[i] == '0') ? 1 : 0);
        }
        int tot_zero = 0;
        for(char ch : s) tot_zero  += (ch =='0') ? 1 : 0;

        for(int i=0;i < strs.size();i++){

            string t = strs[i];

            int fixed_zero = 0,q_mark = 0;
            
            for(char ch : t){
                if(ch == '0')fixed_zero++;
                if(ch == '?')q_mark++;
            }

            int rem_need_zero = tot_zero  - fixed_zero;

            if(rem_need_zero < 0 || rem_need_zero > q_mark){
                ans.push_back(false);
                continue;
            }

            bool ok = true;

            int curr_zero = 0;

            for(int i=0;i<n;i++){
                char ch = t[i];
                if(ch == '0'){
                    curr_zero++;
                }else if(ch == '?'){

                    if( rem_need_zero > 0){

                        curr_zero++;
                        rem_need_zero--;
                    }
                }

                if(curr_zero < pfx[i+1]){
                     ok = false;
                     break;
                }
            }

            ans.push_back(ok);


        }

        return ans;
    }
};