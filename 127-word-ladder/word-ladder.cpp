// class Solution {
//     int cnt = 1;
//     int n ;
//     bool bfs(int nod, vector<int>&vis,vector<vector<int>>&adj){

//         vis[nod] = true;
//         queue<int> q; q.push(nod);

//         while(q.empty()){
//             auto cur = q.front();
//             q.pop();

//             if(cur == n-1){
//                 return true;
//             }
//             cnt++;
//             for(auto nr : adj[cur]){
//                 if(!vis[nr]){
//                     vis[nr] = 1;
//                     q.push(nr);
//                 }
//             }

//         }

//         return false;
//     }

// public:
//     int ladderLength(string begin, string end, vector<string>& List) {
        
//          n = List.size();
//         vector<vector<int>> adj(n+1);

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


//         for(int i=0;i<n-1;i++){
//             int dif = 0;
//             for(int j = 0;j<n;j++){
//                     int dif = 0;
//                 if(i != j){
//                     for(int k = 0;k<List[j].size();k++){
//                             if(List[i][k] != List[j][k]){
//                                 dif++;
//                             }
//                     }
//                         if(dif == 1){
//                             adj[i+1].push_back(j+1);
//                         }
//                 }
//             }
//         }
//         vector<int> vis(n+1,0);
//         bool found = bfs(0,vis,adj);

//         if(found){
//             return cnt+1;
//         }

//         return 0;


//     }
// };



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        // Check if endWord exists in wordList
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it == wordList.end()) return 0;
        int endIndex = distance(wordList.begin(), it) + 1; // +1 because beginWord is at index 0

        // Build adjacency list
        vector<vector<int>> adj(n+1);
        
        // Connect beginWord to words differing by 1
        for(int i=0; i<n; i++){
            int dif = 0;
            for(int j=0; j<beginWord.size(); j++){
                if(beginWord[j] != wordList[i][j]) dif++;
            }
            if(dif == 1) adj[0].push_back(i+1);
        }

        // Connect words in wordList
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dif = 0;
                for(int k=0; k<wordList[i].size(); k++){
                    if(wordList[i][k] != wordList[j][k]) dif++;
                }
                if(dif == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        // BFS
        vector<int> dist(n+1, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 1; // beginWord counts as step 1

        while(!q.empty()){
            int cur = q.front(); q.pop();
            if(cur == endIndex) return dist[cur];
            for(auto nxt : adj[cur]){
                if(dist[nxt] == -1){
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }

        return 0;
    }
};