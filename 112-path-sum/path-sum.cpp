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
    
    bool pathsum(TreeNode* root, int target,int c_sum){

        if(root == nullptr) return false;

        c_sum += root->val;

        // if the leaf nodes matches

        if(!root->left && !root->right){
            return c_sum == target;
        }

        
       return  pathsum(root->left,target,c_sum) || pathsum(root->right,target,c_sum);;
    

    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return pathsum(root,targetSum,0);
    }
};