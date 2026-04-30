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
    int cnt = 0;
    void solve(TreeNode* root,int mx){

        if(!root)return ;

        if(root->val >= mx) cnt++;

        solve(root->left,max(root->val,mx));
        solve(root->right,max(root->val,mx));
    }
public:
    int goodNodes(TreeNode* root) {
         solve(root,-1e5);

         return cnt;
    }
};