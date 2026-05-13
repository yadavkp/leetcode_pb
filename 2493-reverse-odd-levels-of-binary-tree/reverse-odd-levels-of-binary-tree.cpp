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
    // simple bfs i used , here , dont swap pointer , only swap value at the pointer 
    // here 
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){

            int sz = q.size();
            
            vector<TreeNode*> point;
            
            while(sz--){
                auto nod = q.front();q.pop();

                point.push_back(nod);
                if(nod->left)q.push(nod->left);
                if(nod->right)q.push(nod->right);
            }

            if(flag){
                int l = 0,r = point.size()-1;
                while(l < r){
                    swap(point[l]->val,point[r]->val);
                    l++,r--;
                }
            }
            flag =!flag;
        }

        return root;
    }
};



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
    
// public:
// void reverse(queue<TreeNode*>&q){

//         stack<TreeNode*> st;
//         while(!q.empty()){
//             st.push(q.front());
//             q.pop();
//         }

//         while(!st.empty()){
//             q.push(st.top());
//             st.pop();
//         }

//     }

//     TreeNode* reverseOddLevels(TreeNode* root) {
        
//         TreeNode* root1 = root;

//         queue<TreeNode*> q2;
//         queue<TreeNode*> q1;
//         int flag = 1;
//         q1.push(root);q2.push(root);
//         while(!q1.empty()){
//             int sz = q1.size();
           

//             while(sz--){
//                 auto nod = q1.front();q1.pop();
                
//                  if(nod->left)q1.push(nod->left);
//                  if(nod->right)q1.push(nod->right);
//             }
//             queue<TreeNode*> q3;
//             q3 = q1;

//             if(flag){
//                  reverse(q3);
//             }

//             flag  = !flag;
//              sz = q2.size();
//             while(sz--){
//                 auto nod = q2.front();q2.pop();
//                 nod->left = q3.front();
//                 q2.push(q3.front());
//                 q3.pop();
//                 nod->right = q3.front();
//                 q2.push(q3.front());q3.pop();
//             }


//         }

//         return root1;
//     }
// };