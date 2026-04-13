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
    int minD(TreeNode* root){
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return 1;

        return 1 + min(minD(root->left),minD(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;  //check if root is NULL.
        return minD(root);
    }


    //PLEASE UP VOTE BROTHERS AND CUTIES..
};