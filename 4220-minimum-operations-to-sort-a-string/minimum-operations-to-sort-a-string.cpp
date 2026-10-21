class Solution {

    bool sorted(int i,int j,string&s){


        for(int k = i+1;k <= j;k++){
            if(s[k-1] > s[k]) return false;
        }

        return true;
    }
public:
    int minOperations(string s) {
        
        int n = s.size();
        int ops = 3;
        if(n == 2){
            if(s[0] > s[1]) return -1;
            return 0;
        }else if(n==1)return 0;
        else {
            string ss = s;
            int cnt = 0;
            if(!sorted(1,n-1,s)){
                cnt++;
                sort(s.begin()+1,s.end());
            }
            
            if(!sorted(0,n-2,s)){
                cnt++;
                sort(s.begin(),s.begin()+n-1);
               
            }

            if(!sorted(1,n-1,s)){
                cnt++;
                sort(s.begin()+1,s.end());
            }
            ops = min(ops,cnt);
            s = ss;
            cnt = 0;

            if(!sorted(0,n-2,s)){
                cnt++;
                sort(s.begin(),s.begin()+n-1);
               
            }
             if(!sorted(1,n-1,s)){
                cnt++;
                sort(s.begin()+1,s.end());
            }
             if(!sorted(0,n-2,s)){
                cnt++;
                sort(s.begin(),s.begin()+n-1);
               
            }
            ops = min(ops,cnt);
            
           
        }
        return ops;
    }
};