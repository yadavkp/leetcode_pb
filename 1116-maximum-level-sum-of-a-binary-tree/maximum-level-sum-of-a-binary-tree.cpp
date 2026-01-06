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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int mx = root->val;
        
        int level = 1,new_level = 1;;
         while(!q.empty()){

            int sz = q.size();
            int levelsum = 0;

            for(int i=0;i<sz;i++){

                TreeNode* node = q.front();
                q.pop();

                levelsum += node->val;

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr)q.push(node->right);
            }

            if(levelsum > mx){
                level = new_level;
                mx = levelsum;
            }
            new_level++;

         }
        return level;

    }
};