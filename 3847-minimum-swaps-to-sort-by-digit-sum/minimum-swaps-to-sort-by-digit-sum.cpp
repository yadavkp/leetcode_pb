class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> vpp;

        for(int i=0;i < n;i++){
            int val = nums[i];
            int sum = 0;
            while(val > 0){
                sum += (val % 10);
                val /= 10;
            }
            vpp.push_back({sum,nums[i]});
        }
        
        auto temp = [&](auto a, auto b){

           if(a.first != b.first) return a.first < b.first;
           
           return a.second < b.second;
        };

        sort(vpp.begin(),vpp.end(),temp);

        // Sorted ho gaya — vpp mein

            // Position map banao
            // value → uski sorted position
            map<int,int> pos;
            for(int i = 0; i < n; i++){
                pos[vpp[i].second] = i;
            }

            // Cycle detect karo
            vector<bool> visited(n, false);
            int swaps = 0;

                for(int i = 0; i < n; i++){
                    if(visited[i]) continue;
                    if(vpp[i].second == nums[i]){
                        visited[i] = true;
                        continue;
                    }
                    
                    int cycle = 0;
                    int j = i;
                    while(!visited[j]){
                        visited[j] = true;
                        j = pos[nums[j]];
                        cycle++;
                    }
                    swaps += cycle - 1;
                }

             return swaps;
    }
};