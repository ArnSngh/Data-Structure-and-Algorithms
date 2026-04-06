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
    map <int, int> mp;
    int c = 0;

    TreeNode* get(vector <int> &a, int s, int f) {
        if (s > f) return nullptr;

        TreeNode* v = new TreeNode(a[c]);

        int m = mp[a[c++]];

        v->left = get(a, s, m - 1);
        v->right = get(a, m + 1, f);

        return v;
    }
    TreeNode* buildTree(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < b.size(); i++) mp[b[i]] = i;
        
        return get(a, 0, b.size() - 1);
    }
};