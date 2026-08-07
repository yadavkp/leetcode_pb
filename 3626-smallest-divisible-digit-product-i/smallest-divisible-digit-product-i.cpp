class Solution {

    int give_pdt(int n){

        string s = to_string(n);

        int pdt = 1;
        for(int i=0;i < s.size(); i++){
            pdt *=  (s[i] - '0');
        }

        return pdt;
    }
public:
    int smallestNumber(int n, int t) {
        

        while(true){

            int pdt = give_pdt(n);
            cout<<pdt<<" \n";

            if(pdt%t ==0 ) return n;
            n++;
        }

        return 0;
    }
};