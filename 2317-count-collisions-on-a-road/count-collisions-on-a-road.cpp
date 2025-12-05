class Solution {
public:
    int countCollisions(string dir) {
        
        int cnt = 0;
        stack<char> s;
        for(int i=0;i<dir.size();i++){
           if(dir[i]=='R')s.push('R');
           else if(dir[i]=='S'){
                if(s.empty())s.push('S');
                else{
                    int col = 0;
                    while(!s.empty() && s.top() == 'R'){
                        s.pop();
                        cnt++;
                        col = 1;
                    }
                    if(s.empty() && col ){
                        s.push('S');
                    }
                }
           }else if(dir[i] == 'L'){
            int col = 0;
            if(!s.empty() && s.top() == 'S'){
                cnt++;
                continue;

             }
             while(!s.empty() && s.top() == 'R'){
                 // once r collide with L , then count +2, then after R collide with S , then it give count  +1, not +2

                cnt += (col == 1 ? 1 : 2);
                col=1;
                s.pop();
                
             }
             if(s.empty() && col){
                s.push('S');

             }
           }
        }

        return cnt;
    }
};