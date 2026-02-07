class Solution {

public:

    int minimumDeletions(string s) {
        
        s = 'A' + s;
        s = s + 'B';
         int n = s.size();
         vector<int> b_pfx(n,0),a_sfx(n,0);

         for(int i=0;i<n;i++){
            int cnt = 0;
            if(s[i]=='b'){
                cnt++;
            }
            b_pfx[i] = (i > 0 ? b_pfx[i-1]+cnt : 0);
         }

          for(int i=n-1;i>=0;i--){
            int cnt = 0;
            if(s[i]=='a'){
               cnt++;

            }
            a_sfx[i] = (i < n-1 ? a_sfx[i+1] + cnt : 0);
         }

         int sum = 1e9;

         for(int i=1;i<n-1;i++){
            sum = min(sum,b_pfx[i-1] +  a_sfx[i+1] );
            
         }
        return sum;
    }
};