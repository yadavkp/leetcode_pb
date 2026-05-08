class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int mx = 0;
        for(int i=0;i<arr.size()-1;){

            if(arr[i] < arr[i+1]){
                  int j = i;
                  int l1 = 1;
                    while(j +1 < arr.size() && arr[j] < arr[j+1]){
                        j++;
                        l1++;
                        
                    }
                    // if(i!= j){
                    //     j--;
                    // }
                int ok = 0;
                int l2 = 0;
                    while(j +1 < arr.size() && arr[j] > arr[j+1]){
                        j++;
                        
                        ok = 1;
                        l2++;
                        
                    }
                    //cout<<"dkf"<<j;
                    if(ok){
                        ok = 0;
                        mx = max(mx,l1+l2);
                    }
                    // if(i!= j){
                    //     i = j-1;
                    // }
                    //cout<<" "<<j<<" ";
                    i = j;

          }else{
            i++;
          }
        }

        return mx;
    }
};