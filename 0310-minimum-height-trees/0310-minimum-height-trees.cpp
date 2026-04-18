
class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    
        // Edge case
        if(n==1){
            return {0};
        }
        
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        vector<int> ans;

        for(auto it:edges)
        {
            //update adjacency list and indegree for each node 
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }

        queue<int> q;

        //push all the leaf nodes in the queue
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1){
                q.push(i);
            }
        }

        int nodes=n;

        // iteratively update the nodes by removing leaf nodes
        while(nodes>2){

            int size=q.size();
            nodes-=size;

            for(int i=0;i<size;i++)
            {
                int curr=q.front();
                q.pop();

                for(auto it:adj[curr])
                {
                    //update the indegree of adjacent nodes of leaf node
                    degree[it]--;
                    
                    //push the node in queue if it is a leaf node now
                    if(degree[it]==1){
                     q.push(it);
                    }
                }
            }

        }

        // push the root nodes in answer array 
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};