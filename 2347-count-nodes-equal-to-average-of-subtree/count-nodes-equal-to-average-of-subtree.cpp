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
    pair<int,int>  solve(TreeNode* root){

        if(root->left == nullptr && root->right == nullptr){
            cnt += 1;
            return {root->val,1};
        }

        int sum = 0;
        sum += root->val;
        int nod_cnt = 0;
        if(root->left != nullptr){
            auto [v,depth]= solve(root->left);
            nod_cnt += depth;
            sum += v;
        }
        if(root->right != nullptr){
            auto [v,depth]= solve(root->right);
            nod_cnt += depth;
            sum += v;
        }

        nod_cnt += 1; // + 1 for current nod

        if( ((root->val) == (sum / nod_cnt))) cnt += 1;

        return {sum, nod_cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        
     
         solve(root);
         return cnt;
    }
};