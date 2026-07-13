class Solution {
    vector<string> ans;
    string s;
    void solve(int idx,int tight,int prev,string ss){
        
        if(idx == s.size()){
            if(!ss.empty()){
                ans.push_back(ss);
            }
            return ;
        }

        // if(!ss.empty()){
        //        cout<<ss<<"\n";
        // }

        int limit = tight ? s[idx]-'0' : 9;

        for(int dig = 0; dig <= limit; dig++){

            int new_tight = tight && (dig == s[idx]-'0');

            if(prev+1 == dig || prev <=0){
                string new_ss = ss + to_string(dig);
                solve(idx+1,new_tight,dig,new_ss);
            }
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        
        s = to_string(high);

        solve(0,1,-1,"");

        vector<int> arr;
        for(auto &s : ans){
            arr.push_back(stoi(s));
        }
        sort(arr.begin(),arr.end());
        vector<int> ans1;
        for(int i=0;i<arr.size();i++){

           if(arr[i] >=low && arr[i] <= high){
            ans1.push_back(arr[i]);
           }
        }

        return ans1;

    }
};