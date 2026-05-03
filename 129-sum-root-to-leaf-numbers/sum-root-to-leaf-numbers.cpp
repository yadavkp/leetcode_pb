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

// class Solution {
//     int ans = 0;

//     void solve(TreeNode* root,int sum){

//         if(!root) return ;
        
//         if(!root->left && !root->right){
//             ans += sum;
//             return;
//         }

//         if(root->left)solve(root->left,sum*10 + root->left->val);
//         if(root->right)solve(root->right,sum*10 + root->right->val);

//     }

// public:
//     int sumNumbers(TreeNode* root) {
//         int sum = 0;
//         solve(root,root->val);

//         return ans;
//     }
// };




class Solution {
    

    int  solve(TreeNode* root,int sum){

        if(!root) return 0 ;
        int ans = 0;
        if(!root->left && !root->right){
            return sum;
            
        }

        if(root->left)ans += solve(root->left,sum*10 + root->left->val);
        if(root->right)ans += solve(root->right,sum*10 + root->right->val);

        return ans;

    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return solve(root,root->val);

        
    }
};