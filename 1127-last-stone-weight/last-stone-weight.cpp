class Solution {
public:
    int lastStoneWeight(vector<int>& stn) {
        sort(stn.rbegin(),stn.rend());
        deque<int> dq(stn.begin(),stn.end());

        for(auto t : dq)cout<<t;
        while(dq.size() > 1){
            int f = dq.front();
            dq.pop_front();
            int s = dq.front();
            dq.pop_front();
            if(f != s){
                dq.push_front(f-s);
            }
            sort(dq.rbegin(),dq.rend());
        }

        return (dq.empty() ? 0 : dq.front());
    }
};