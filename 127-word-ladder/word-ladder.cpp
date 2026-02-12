
class Solution {
    int cnt = 0;
    int n ;
   
public:
    int ladderLength(string begin, string end, vector<string>& List) {
        
        n = List.size();

        set<string> seen;
        for(auto vec : List){
            seen.insert(vec);
        }

        if(seen.find(end) ==  seen.end()) return 0;

        queue<pair<string,int>> q;q.push({begin,1});

        while(!q.empty()){

            auto p = q.front(); q.pop();

            string s = p.first;
            int level = p.second;

            if(s == end){
                return level;
            }

          

                for(int j = 0;j<s.size();j++){
                    for(char ch = 'a';ch <= 'z';ch++){
                        string n_w = s;
                        n_w[j] = ch;
                        if(seen.find(n_w) !=  seen.end()){
                            q.push({n_w,level+1});
                            seen.erase(n_w);

                            cout<<n_w<<" ";
                        }
                     }
                }
            
        }


        return 0;
        
    }
};













// class Solution {
//     int cnt = 0;
//     int n ;
//     bool bfs(int nod,int end_idx, vector<int>&vis,vector<vector<int>>&adj){

//         vis[nod] = true;
//         queue<int> q; 
//         q.push(nod);

//         while(!q.empty()){
//             int sz = q.size();
//             cnt++;
//            while(sz--){
//                  auto cur = q.front();      q.pop();
               
//                 if(cur == end_idx) return true;
                    
//                 for(auto nr : adj[cur]){
//                     if(!vis[nr]){
//                         vis[nr] = 1;
//                         q.push(nr);
//                     }
//                 }
//             }

//         }

//         return false;
//     }

// public:
//     int ladderLength(string begin, string end, vector<string>& List) {
        
//          n = List.size();

//         vector<vector<int>> adj(n+1);

//         auto it = find(List.begin(),List.end(),end);

//         if(it == List.end()) return 0;
        
        
//         auto end_idx = distance(List.begin(),it) + 1;

//         for(int i=0;i<n;i++){
//             int dif = 0;
//             for(int j = 0;j<List[i].size();j++){
//                 if(begin[j] != List[i][j]){
//                     dif++;
//                 }
//             }
//             if(dif==1){
//                 adj[0].push_back(i+1);
//             }
//         }


//         for(int i=0;i<n;i++){
//             int dif = 0;
//             for(int j = 0;j<n;j++){
//                     int dif = 0;
              
//                         for(int k = 0;k<List[j].size();k++){
//                             if(List[i][k] != List[j][k]){
//                                 dif++;
//                             }
//                         }

//                         if(dif == 1){
//                             adj[i+1].push_back(j+1);
//                             adj[j+1].push_back(i+1);
//                         }
//             }
//         }

//         vector<int> vis(n+1,0);

//         bool found = bfs(0,end_idx,vis,adj);

//         if(found){
//             return cnt;
//         }

//         return 0;


//     }
// };


