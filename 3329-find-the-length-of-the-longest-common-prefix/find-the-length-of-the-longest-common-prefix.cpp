
class Solution {
    #define ll long long

     map<int,int> mp;
     int get_dig(int val1){
        int cnt = 0;
        while(val1 > 0){
            cnt++;
            val1 /= 10;
            
        }
        return cnt;
    }

    int check(int val1){
        int pfx_dig = 0;
        while(val1 > 0){
           
           if(mp.count(val1)){
            pfx_dig = get_dig(val1);
              break;
            }
            val1 /= 10;
        }
        return pfx_dig;
    }

    void store_in_map(int val2){
        mp[val2]++;
        while(val2 > 0){
            val2 /= 10;
            mp[val2]++;
            
        }
    }


public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        int mx = 0;
        for(int i=0;i<arr1.size();i++){
            store_in_map(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){

          mx = max(mx, check(arr2[i]));
        }


        return mx;

    }
};