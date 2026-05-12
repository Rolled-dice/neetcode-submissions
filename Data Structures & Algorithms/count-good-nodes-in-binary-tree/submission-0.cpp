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
    int solve (TreeNode *root,int maxi){
         if(!root)return 0;
         int res=root->val>=maxi?1:0;
         maxi=max(maxi,root->val);
         res+=solve(root->left,maxi);
         res+=solve(root->right,maxi);
         return res;
    } 
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};
