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
    unordered_map<TreeNode*,int> dp;

    int solve(TreeNode* root){

        if(root == nullptr) return 0;

        if(dp[root]) return dp[root];

        int include = root->val;
        if(root->left != nullptr){
            include += solve(root->left->left);
            include += solve(root->left->right);
        }
        if(root->right != nullptr){
            include += solve(root->right->left);
            include += solve(root->right->right);
        }

        int exclude = solve(root->left) + solve(root->right);

        return dp[root] =  max(include,exclude);
    }
public:
    int rob(TreeNode* root) {
        
        return solve(root);
    }
};