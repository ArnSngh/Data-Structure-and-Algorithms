class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

            long long minIndex = q.front().second;
            long long first, last;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long curr = q.front().second - minIndex;
                q.pop();

                if (i == 0) first = curr;
                if (i == size - 1) last = curr;

                if (node->left)
                    q.push({node->left, 2 * curr + 1});

                if (node->right)
                    q.push({node->right, 2 * curr + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};