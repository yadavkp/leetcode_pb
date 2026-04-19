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

    int count_path(TreeNode* root, int tar,long long sum){

        if(root  == nullptr) return 0;
        int count = 0;
        sum += root->val;


        if(sum == tar) count++;

        count += count_path(root->left,tar, sum);
        count += count_path(root->right,tar, sum);

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr ) return 0;

        int res = count_path(root,targetSum,0);

        res += pathSum(root->left,targetSum);
        res += pathSum(root->right,targetSum);

        return res;

    }
};