class Solution {
public:
    vector<vector<int>> generate(int n) {
        #define pb push_back
        vector<vector<int>> ans;
        vector<int> a;
        a.pb(1);
        ans.pb(a);
        while(n>1){

            vector<int> temp;temp.pb(1);
            for(int i=1;i<=a.size()-1;i++){
                temp.pb(a[i-1] + a[i]);
            }
            temp.pb(1);
            a = temp;
            ans.pb(temp);
            n--;
        }

        return ans;

    }
};