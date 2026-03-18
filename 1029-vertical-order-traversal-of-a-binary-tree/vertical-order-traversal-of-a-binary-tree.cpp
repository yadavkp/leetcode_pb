/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//method 1->  by dfs this can solved by easy way
// method 2 -> BY bfs this can also solved 


// class Solution {
//     map<int,map<int,multiset<int> >> mp;
//     void solve(TreeNode* root,int idx,int level){

//         if(root == nullptr)return;

//         mp[idx][level].insert(root->val);

//         solve(root->left,idx-1,level+1);
//         solve(root->right,idx+1,level+1);
//     }
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
        
//         solve(root,0,0);

//         vector<vector<int>> adj;

//         for(auto[x,y] : mp){
//             vector<int> temp;
//             for(auto [levl,mul] : y){
//                 temp.insert(temp.end(),mul.begin(),mul.end());
//             }
//             adj.push_back(temp);

//         }



//         return adj;
//     }
// };







class Solution {
    map<int,map<int,multiset<int> >> mp;
   
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       

        queue<pair<TreeNode* , pair<int,int> >> q;
        q.push({root,{0,0}});

        while(!q.empty()){

            auto [nod,pr] = q.front(); q.pop();
            auto [x,y] = pr; // hre x colm, and y , as a row

            mp[x][y].insert(nod->val);

            if(nod->left) q.push({nod->left,{x-1,y+1}});
            if(nod->right)q.push({nod->right,{x+1,y+1}});

        }


        vector<vector<int>> adj;

        for(auto[x,y] : mp){
            vector<int> temp;
            for(auto [levl,mul] : y){
                temp.insert(temp.end(),mul.begin(),mul.end());
            }
            adj.push_back(temp);

        }



        return adj;
    }
};