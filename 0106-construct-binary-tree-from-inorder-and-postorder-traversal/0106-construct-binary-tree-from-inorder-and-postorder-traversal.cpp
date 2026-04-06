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
    TreeNode* solve(vector<int> &in, vector<int> &p, unordered_map<int,int> &mp, int inSt, int inE, int& idx) {
        if(inSt > inE) return NULL;
        int val = p[idx--];
        TreeNode* root = new TreeNode(val);
        int pos = mp[val];
        root -> right = solve(in, p, mp, pos+1, inE, idx);
        root -> left = solve(in, p, mp, inSt, pos-1, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int idx = postorder.size()-1;
        return solve(inorder, postorder, mp, 0, inorder.size()-1, idx);
    }
};