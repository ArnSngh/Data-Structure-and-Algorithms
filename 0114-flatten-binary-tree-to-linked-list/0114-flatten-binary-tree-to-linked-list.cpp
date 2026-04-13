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

    TreeNode* ft(TreeNode* node){
        if(node == NULL){
            return NULL;
        }
        if(node->left == NULL && node->right == NULL){
            return node;
        }
        TreeNode* ltail = ft(node->left);
        TreeNode* rtail = ft(node->right);

        if(ltail!=NULL){
            ltail->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        return rtail == NULL ? ltail : rtail;
    }
    void flatten(TreeNode* root) {
        ft(root);
    }
};