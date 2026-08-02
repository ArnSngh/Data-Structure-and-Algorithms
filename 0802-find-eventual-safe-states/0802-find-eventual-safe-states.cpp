class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<vector<int>> revgraph(v);
        vector<int> indegree(v, 0);

        for(int i = 0; i < v; i++){
            for(int j = 0; j < graph[i].size(); j++){
                int neighbour = graph[i][j];
                revgraph[neighbour].push_back(i);
            }
        }

        for(int i = 0; i < v; i++){
            for(int j = 0; j < revgraph[i].size(); j++){
                int neighbour = revgraph[i][j];
                indegree[neighbour]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int i = 0; i < revgraph[node].size(); i++){
                int neighbour = revgraph[node][i];

                indegree[neighbour]--;

                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};