class Solution {

    #define ll long long
    bool perfect_sq( ll n){

        ll nn = sqrt(n);

        if(nn* nn == n)return true;

        return false;
    }
public:
    int maximumLength(vector<int>& nums) {


        unordered_map<int,int> p_sq;
        unordered_map<int,int> mp;
        int mx = 0;
        int one = 0;
        for(auto v : nums){
            if(perfect_sq(v) && !p_sq.count(v) && v > 1){
                p_sq[v]++;
            }
            if(v == 1)one++;
        }
        mx = one;
        if(one %2==0){
            mx = one-1;
        }
        
        for(auto v : nums) mp[v]++;
        for(auto [i,f] : p_sq){
            int cnt = 1;
                for(int j = i; j > 0;){
                    if(perfect_sq(j) && mp[sqrt(j)] >= 2){
                         // for better redce 2, in case v = 1;
                        cnt += 2;
                    }else break;
                    j = sqrt(j);
                    cout<<j<<" ";
                }
                cout<<" \n";
            
            mx = max(mx, cnt);
        }

        return ((mx <= 0) ? 1 : mx);
    }
};