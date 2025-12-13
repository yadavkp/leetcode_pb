#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

// ordered_set with order statistics 
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

class Solution {
public:
    long long totalScore(int hp, vector<int>& dam, vector<int>& req) {
        int n = dam.size();
        vector<ll> pfx(n,0);
        pfx[0] = dam[0];
        for (int i = 1; i < n; i++) pfx[i] = pfx[i-1] + dam[i];

        ordered_set<ll> os;
        
        ll score = 0;

        for (int i = n-1;i>=0;i--) {
            os.insert((ll)hp - pfx[i] - req[i]);

            int v = (i>0 ? -pfx[i-1] : 0);
            score += (ll)os.size()- (os.order_of_key(v)); // it give the value <v in set
            
        }
        return score;
    }
};