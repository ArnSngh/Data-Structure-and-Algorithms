class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool LTR = 1;

        while(!q.empty()) {//each 1 cycle
        int size = q.size();
        vector<int> temp(size);
        for(int i = 0; i<size; i++){ // this loop is for traversing through each element in queue in this current cycle
            TreeNode* node = q.front(); // lets pickup the first element
            // now we want to push this element in temp according to the flag wheter at starting or at last...and then push its children in the queue itself
            q.pop(); // remove that paretn node
            if(LTR){
                // we want to fill left to right then we will fill the temp vector from starting that is from i
                temp[i] = node->val;
            }
            else{
                temp[size-1-i] = node->val; //agr LTR nhi hai to last element bhrna chaalu krenge...lets say size = 4 them temp[4-1-0] = temp[3] mtlb last element
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        LTR = !LTR; // reverse the direction
        ans.push_back(temp);        
        }
        return ans;

        
    }
};