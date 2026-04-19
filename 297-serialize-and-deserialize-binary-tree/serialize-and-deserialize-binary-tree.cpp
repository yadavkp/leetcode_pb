/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        queue<TreeNode*> q;
        string data = "";
        q.push(root);
        while(!q.empty()){

            auto nod = q.front();q.pop();

            if(nod == nullptr) data += "#,";
            else {
                data += to_string(nod->val) + ",";
                q.push(nod->left);
                q.push(nod->right);
            }
        }

        return data;
    }

    vector<string> split(const string&s,char delimeter){

        vector<string> tokens;
        stringstream ss(s);
        string var;

        while(getline(ss,var,delimeter)){
            tokens.push_back(var);
        }
        return tokens;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data[0] == '#') return nullptr;

        vector<string> st = split(data,','); // generate token

        TreeNode* root = new TreeNode(stoi(st[0]));

        queue<TreeNode*> q;
        int i=1;
        q.push(root);
        while(!q.empty() && i < st.size()){

            auto nod = q.front();q.pop();

            if(i < st.size() && !st.empty() && st[i] != "#"){
                nod->left = new TreeNode(stoi(st[i]));
                q.push(nod->left);
            }
            i++;

            if(i < st.size() && !st.empty()  && st[i] != "#"){
                nod->right = new TreeNode(stoi(st[i]));
                q.push(nod->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));