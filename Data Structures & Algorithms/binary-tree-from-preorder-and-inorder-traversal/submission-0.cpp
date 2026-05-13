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
    TreeNode* solve(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie){
        if(ps>pe|| is>ie)return NULL;
        TreeNode* node=new TreeNode(preorder[ps]);
        int idx=-1;
        for(int i=is;i<=ie;i++){
             if(preorder[ps]==inorder[i]){
                idx=i;
                break;
             }
        }
        int leftsize=idx-is;
        node->left=solve(preorder,ps+1,ps+leftsize,inorder,is,idx-1);
        node->right=solve(preorder,ps+leftsize+1,pe,inorder,idx+1,ie);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
