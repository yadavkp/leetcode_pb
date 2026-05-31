class Solution {

    void extract(vector<int>&frq,int n){

        while(n > 0){
            frq[n%10]++;
            n /= 10;
        }
    }

public:
    int digitFrequencyScore(int n) {
        
        vector<int> frq(10,0);
        extract(frq,n);

        int sum = 0;
        for(int i=1;i<10;i++){
            sum += i * frq[i];
        }

        return sum;
    }
};