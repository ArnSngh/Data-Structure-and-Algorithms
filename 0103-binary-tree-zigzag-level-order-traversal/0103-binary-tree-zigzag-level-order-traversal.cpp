/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        bool direction = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            //process all elements of the same level
            while (n) {
                TreeNode* frontNode = q.front();
                q.pop();
                temp.push_back(frontNode->val);
                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
                n--;
            }
            if (direction == 0 && !temp.empty()) {
                ans.push_back(temp);
                direction = 1;
            } else if (direction == 1 && !temp.empty()) {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                direction = 0;
            }
        }
        return ans;
    }
};