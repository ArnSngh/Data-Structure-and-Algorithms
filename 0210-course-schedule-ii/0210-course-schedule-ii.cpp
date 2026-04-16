class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // adjacency list banayenge
        // adj[u] -> kaun kaun se course depend karte hain u par
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++){

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            // v pehle karna padega tab u kar sakte hain
            adj[v].push_back(u);
        }


        // indegree array -> kitne prerequisites hain har course ke
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++){

            for(auto it : adj[i]){

                indegree[it]++;
            }
        }


        // queue for Kahn's Algorithm (BFS Topological Sort)
        queue<int> q;

        // jinka indegree 0 hai wo pehle kiye ja sakte hain
        for(int i = 0; i < numCourses; i++){

            if(indegree[i] == 0){

                q.push(i);
            }
        }


        vector<int> ans ;


        // Kahn's Algorithm start
        while(!q.empty()){

            int node = q.front();
            q.pop();

            ans.push_back(node);

            // neighbours ka indegree kam karo
            for(auto it : adj[node]){

                indegree[it]--;

                if(indegree[it] == 0){

                    q.push(it);
                }
            }
        }
        
        
        // ✅ important check
        if(ans.size() != numCourses){
            return {};
        }

        return ans;
      
    }
};