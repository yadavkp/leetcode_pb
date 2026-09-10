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
    //vector<int> depth;
    int cnt = 0;
    pair<int,int>  solve(TreeNode* root){

        if(root->left == nullptr && root->right == nullptr){
            cnt += 1;
            return {root->val,1};
        }

        int sum = 0;
        sum += root->val;
        int tot = 0;
        if(root->left != nullptr){
            auto [v,depth]= solve(root->left);
            tot += depth;
            sum += v;
        }
        if(root->right != nullptr){
            auto [v,depth]= solve(root->right);
            tot += depth;
            sum += v;
        }
        tot += 1;

        if(tot > 0  && ((root->val) == (sum / tot))) cnt += 1;

       // cout<< sum <<" "<< tot<<" \n";

        return {sum, tot};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        
     
         solve(root);
         return cnt;
    }
};