class Solution {
public:
    int res = INT_MIN;

    int solve(TreeNode* root) { 
        if (!root) return 0;

        int lh = max(0, solve(root->left));
        int rh = max(0, solve(root->right));

        res = max(res, root->val + lh + rh);

        return root->val + max(lh, rh);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }
};
