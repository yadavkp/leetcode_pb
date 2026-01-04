class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& s) {
        

        vector<vector<string>> ans;
        sort(s.begin(),s.end());
         int n = s.size();
         for(int i = 0;i < n;i++){
            string top = s[i];
            for(int j = 0; j< n; j++){
                    string left = s[j];
                if(i != j && top[0] == left[0]){
                    for(int k = 0; k< n ;k++){
                        string right = s[k];
                        if(i != k && j != k && top[3] == right[0]){
                            for(int l = 0; l < n ; l++){
                                string bottom = s[l];
                                if(l != i && l != j && l != k && left[3] == bottom[0] && right[3] == bottom[3]){
                                    ans.push_back({top,left,right,bottom});
                                }
                            }
                        }
                    }
                }
            }
         }
       // sort(ans.begin(),ans.end());
        return ans;
    }

    
};