class Solution {
public:
    int totalSteps(vector<int>& a) {
        stack<pair<int,int>> st;

        int cnt = 0,n = a.size();
        st.push({a[n-1],0});

        for(int i=n-2;i>=0;i--){
            int del = 0;
            while(!st.empty() && a[i] > st.top().first){
                del  =  max(del+1,st.top().second); // +1 because of removal of 1 nums
                st.pop();
                
            }
            cnt = max(del,cnt);
            st.push({a[i],del});
        }

        return cnt;
    }
};