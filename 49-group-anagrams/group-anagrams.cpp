class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> seen;
        for(auto s : strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            seen[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto [key , group] : seen){
            ans.push_back(group);
        }
        return ans;
    }
};