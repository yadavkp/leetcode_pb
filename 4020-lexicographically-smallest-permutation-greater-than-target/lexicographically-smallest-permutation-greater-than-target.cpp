class Solution {
    #define pb push_back
    vector<int> frq;
    string ans = "";
    void dfs(int i,int f,string &ss,string &tar){
        
        if(i >= tar.size()){
            if(f == 1){
                if(ans.empty()) ans = ss;
                
            }
           
            return ;
        }


        for(int k = 0;k  < 26; k++){

           
            if(frq[k] > 0){

                char ch = k + 'a';

                 if(ch == tar[i]){
                   ss += ch;
                   frq[ch-'a']--;
                    dfs(i+1,0,ss,tar);
                    frq[ch-'a']++;
                    ss.pop_back();


                    if(!ans.empty()) return ;
                    
                }else if(ch > tar[i]){

                    ss += ch;
                    frq[ch-'a']--;
                   
                    for(int l = 0;l < 26;l++){
                            while(frq[l]>0){
                                ss += (l + 'a');
                                frq[l]--;
                            }
                    }
                    ans = ss;
                    
                    return;

                }
                
            }
        }


    }
public:
    string lexGreaterPermutation(string s, string target) {
        
        frq.assign(26,0);
        ans = "";
        for(char ch : s){
            frq[ch -'a']++;
        }

        string ss = "";
        
        dfs(0,0,ss,target);

        return ans;
    }
};