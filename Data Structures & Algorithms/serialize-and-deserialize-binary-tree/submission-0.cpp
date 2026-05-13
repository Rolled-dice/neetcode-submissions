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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string s;
        if(!root) return "";
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()){
            TreeNode *node=q.front();q.pop();
            if(node){
                 s+=to_string(node->val)+",";
                 q.push(node->left);
                 q.push(node->right);
            }else s+="#,";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
         if(!s.size())return NULL;
         stringstream ss(s);
         string val;
         getline(ss,val,',');
         queue<TreeNode*>q;
         TreeNode* root=new TreeNode(stoi(val)); 
         q.push(root);
         while(q.size()){
             TreeNode *node=q.front();q.pop();
             getline(ss,val,',');
             if (val != "#") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            // right child
            getline(ss, val, ',');
            if (val != "#") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
         }
         }
       return root;
    }
};
