
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> q;
        vector<int> ans;
        if(!root) return ans;
        q.push_back(root);

        // bfs traverse 
        while(!q.empty()){
            int size = q.size();

            ans.push_back(q.back()->val);  // store ans here
            
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop_front();
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
            }
        }
        return ans;
    }
};