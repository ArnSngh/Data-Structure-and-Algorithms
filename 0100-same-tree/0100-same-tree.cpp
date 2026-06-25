class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //me define kr deta mereko kha kha false milega kya kya condition pe dikkat hogi fir return krdunga last me left recursive call and right recursive call ka && taaki agr ek bhi false ho to loda false return krde
        if(p == nullptr && q== nullptr){
            return true;
        }
        // agr dono saath khtm hogye to thik hai but agr alag hue to galat baat hai
        if(p == nullptr || q == nullptr){
            return false;
        }
        if(p->val!= q->val){
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};