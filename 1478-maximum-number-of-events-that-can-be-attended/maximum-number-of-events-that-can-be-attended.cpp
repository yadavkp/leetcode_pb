class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
       
        int n = events.size();
        sort(events.begin(),events.end());
        int i=0,cnt=0,day=1;
        priority_queue<int,vector<int>,greater<int> > pq;

        while(i < events.size() ||  !pq.empty()){

            if(pq.empty()){
                day = events[i][0];
            }

            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top() < day){
                
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                cnt++;
            }

            day++;
        }

        return cnt;
    }
};