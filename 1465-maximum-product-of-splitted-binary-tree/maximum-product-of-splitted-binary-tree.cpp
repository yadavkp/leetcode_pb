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


//  class Solution {

//     #define ll long long
//     int mod = 1e9 + 7;
//     ll tot_sum = 0, ans = 0;

//     ll getsum(TreeNode* root) {
//         if (!root) return 0;
//         return root->val + getsum(root->left) + getsum(root->right);
//     }

//     ll dfs(TreeNode* root) {
//         if (!root) return 0;
//         ll curr = root->val + dfs(root->left) + dfs(root->right);
//         ans = max(ans, curr * (tot_sum - curr));
//         return curr;
//     }

// public:
//     int maxProduct(TreeNode* root) {
//         tot_sum = getsum(root);
//         dfs(root);
//         return ans % mod;
//     }
// };


//  by using map , still we can solve this pb by well 

 class Solution {

    unordered_map<TreeNode*,int> mp;
    #define ll long long
    int mod = 1e9 + 7;
    ll tot_sum = 0, ans = 0;
    
    ll getsum(TreeNode* root) {
        if (!root) return 0;
        if(mp.count(root)) return mp[root];
        return mp[root]  =  root->val + getsum(root->left) + getsum(root->right);
    }

    ll dfs(TreeNode* root) {
        if (!root) return 0;
        ll curr = root->val + dfs(root->left) + dfs(root->right);
        ans = max(ans, curr * (tot_sum - curr));
        return curr;
    }

public:
    int maxProduct(TreeNode* root) {
        tot_sum = getsum(root);
        dfs(root);
        return ans % mod;
    }
};
