class Solution {
public:
    vector<int> sortByReflection(vector<int>& a) {
        
        auto getbinreflection = [&](int a)-> int
        {
            int rev = 0;
            while(a > 0){
                rev = (rev << 1 | (a&1));
                a >>= 1;
            }
            return rev;
        };
        auto cmp = [&](int a,int b) -> bool
        {
            int bin1 = getbinreflection(a);
            int bin2 = getbinreflection(b);
            if(bin1 == bin2) return a < b;
            return bin1 < bin2;
        };
        sort(a.begin(),a.end(),cmp);
        return a;
    }
};