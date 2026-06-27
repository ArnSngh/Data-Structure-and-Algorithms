class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        //phle ek main map bnaynge jisme ham store krenge kis coordinate me konsa element hai tree ka
        /* map will look like col->{
                                      row->val
                                      row->val
                                      row->val}
        jaha pe pehla jo element col hai vo to int ho ga or andr ek inner map jisme row hone int type but nodes ki value store hogi multiset me unhe ordered me store krne ke liye*/
        map<int,map<int,multiset<int>>> mp;
        /*next we will create a queue data structure jisme ham ek element use krenge jiska type hoga ek pair jo contain krega info about each nodes cordinates

        so ek pair ke andr node hoga node* type ka or fir row col int type ke but vo bhi pair me honge*/
        queue<pair<TreeNode*,pair<int,int>>> q;

        // ab bss root ko push krte fir usse bfs krenge

        q.push({root, {0,0}});

        // BFS loop

        while(!q.empty()){
            // ham auto datatype use krenge kyuki pair<TreenNode,<pair<int,int>>> dataype likhne se acha let the compiler decide which datatype it is
            auto front = q.front();
            q.pop();
            // now we will extract every data fromt that element from queue
            TreeNode* node = front.first; // thats how you access element in the pair.
            int row = front.second.first;
            int col = front.second.second;

            // ab ham bss in sbko map me store krenge
            /* but hey there is a twist...map hamne is trike se bnaya hai
            col->{
                                      row->val
                                      row->val
                                      row->val}

            that means first int in map will be col and the seond type will be row...yup that was the hardest part to understand how our data will be written in the map so we can access it later*/

            mp[col][row].insert(node->val);

            // now agr left hai to left ki condn nhi to right hai to righ ki condn

            if(node->left){
                q.push({node->left, {row+1, col-1}});
            }
            if(node->right){
                q.push({node->right, {row+1, col+1}});
            }
        }

        // now since we have to return the ans in nested vector to bnate hain ek ans or temp vecrtor temp.
        vector<vector<int>>ans;

        for(auto col: mp){
            vector<int> temp;
            for(auto row : col.second){
                for(auto val : row.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;



    }
        
        
};