class Solution {
    unordered_map<string, vector<string>> adj; // To store parents
    unordered_map<string, int> level; // To store levels
    vector<vector<string>> ans;
    
    void dfs(string curr, string target, vector<string>& path) {
        if (curr == target) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for (auto parent : adj[curr]) {
            path.push_back(parent);
            dfs(parent, target, path);
            path.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return {};

        // 1. BFS to find shortest levels
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;
        st.erase(beginWord);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            string temp = curr;
            for (int i = 0; i < curr.size(); i++) {
                char original = curr[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    curr[i] = ch;
                    if (st.count(curr)) {
                        if (level.find(curr) == level.end()) { // New word
                            level[curr] = level[temp] + 1;
                            q.push(curr);
                            adj[curr].push_back(temp);
                        } else if (level[curr] == level[temp] + 1) { // Same level multiple paths
                            adj[curr].push_back(temp);
                        }
                    }
                }
                curr[i] = original;
            }
        }

        // 2. DFS to get all paths
        if (level.count(endWord)) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, path);
        }
        return ans;
    }
};