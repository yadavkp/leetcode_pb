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
        while(true){
            queue<TreeNode*> temp;
            int curr = 0;
            new_level++;
            if(!q.empty()){
                while(!q.empty()){
                        TreeNode* node = q.front();
                        q.pop();
                        if(node->left != nullptr){
                            temp.push(node->left);
                            curr += node->left->val;
                        }
                        if(node->right != nullptr){
                            temp.push(node->right);
                            curr += node->right->val;
                        }

                }
               
                cout<<new_level<<"\n";
                cout<<"mx "<<curr<<"\n";
            }else{
                break;
            }

            if(mx < curr && !temp.empty()){
                mx = curr;
                level = new_level;
            }
            q = temp;
            
        }
        return level;

        


    }
};