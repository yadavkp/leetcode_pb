class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
     
     sort(hBars.begin(),hBars.end());
     sort(vBars.begin(),vBars.end());

     // calculate for hz
        int mx_hz_cons = 1;
        int mx_vt_cons = 1;
        int cur_cons = 1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i] - hBars[i-1] == 1)cur_cons++;
            else cur_cons = 1;
            mx_hz_cons = max(mx_hz_cons,cur_cons);
        }

// calcluate for vertical 
        cur_cons = 1;
        
       
            for(int i=1;i < vBars.size();i++){
               
                    if((vBars[i] - vBars[i-1]) == 1)cur_cons++;
                    else cur_cons = 1;
                    mx_vt_cons = max(mx_vt_cons,cur_cons);

        
             }

        int side = min(mx_hz_cons , mx_vt_cons) + 1;



        return side * side;
    }
};