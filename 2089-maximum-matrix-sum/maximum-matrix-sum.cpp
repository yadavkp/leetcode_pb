#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum = 0,neg = -1e6,cnt=0,zero=0,pos = 1e6;;
        int n = matrix.size(),m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j = 0; j<m ; j++){
             ll val = matrix[i][j];
                if(val < 0){
                    cnt++;
                    neg = max(neg,val);
                }
                if(val == 0)zero++; 
                sum += abs(val);
                if(val > 0)pos = min(pos,val);
            }
        }

        if(cnt%2==0 || zero > 0)return sum;
        else return (sum - min(2* abs(neg),2*pos));

    }
};