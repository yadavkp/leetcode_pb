class Solution {
#define ll long long
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        

        auto cmp = [&](const auto a,const auto b){
            return a[1] < b[1];
        };
        sort(courses.begin(),courses.end(),cmp);
       priority_queue<int> pq;
       ll tot_time = 0,cnt = 0,mx =  0;
        for(auto vec : courses){
            
            tot_time += vec[0];
            cnt++;
           
            pq.push(vec[0]);

            while(!pq.empty() && tot_time > vec[1]){
                tot_time -= pq.top(); pq.pop();
                cnt--;
            }
             mx = max(mx,cnt);

        }

        return mx;
    }
};