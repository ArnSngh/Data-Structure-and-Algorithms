class Solution {
    int solve(TreeNode* root, int &ans){
        if(root == nullptr){
            return 0;
        }

        int lh = solve(root->left, ans);
        int rh = solve(root->right, ans);

        int d = lh + rh;
        ans = max(ans, d);

        return 1 + max(lh, rh);   // height return
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};