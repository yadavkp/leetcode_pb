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


class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        
        unordered_map<int, TreeNode*> mp; // this is use for make relation 
        set<int> seen;                     // this is for tracking

        for(int i=0;i<desc.size();i++){

            auto par = desc[i][0];
            auto child = desc[i][1];
            auto is_left = desc[i][2];

            if(!mp.count(par)){

                TreeNode* temp = new TreeNode(par);
                mp[par] = temp;
            }

            if(!mp.count(child)){
                TreeNode* temp = new TreeNode(child);
                mp[child] = temp;

            }

            if(is_left == 1){
                mp[par]->left = mp[child];
            }else mp[par]->right = mp[child];

            seen.insert(child);

        }
        // if any node does not present in the set , it means that is the root node
        for(int i=0;i<desc.size();i++){

            auto par = desc[i][0];
            auto child = desc[i][1];
            auto is_left = desc[i][2];
            if(!seen.count(par)){
                return mp[par];
            }
        }

        return nullptr;



    }
};