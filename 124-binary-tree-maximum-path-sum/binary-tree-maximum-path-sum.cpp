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
    int res = -1e8;
    int solve(TreeNode* root){
        if(root == nullptr)return 0;

        int lh = max(0,solve(root->left));
        int rh =max(0,solve(root->right));
        int all = root->val + lh + rh;

        res = max({res,all});

        return root->val + max({lh,rh});
    }
public:
    int maxPathSum(TreeNode* root) {
         solve(root);
         return res;
    }
};