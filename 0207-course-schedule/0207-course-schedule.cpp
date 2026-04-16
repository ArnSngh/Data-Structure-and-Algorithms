class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int P = prerequisites.size();
        int N = numCourses;
        vector<int> adj[N];
        vector<int> indeg(N, 0);
        for (int i = 0; i < P; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int j = 0; j < adj[node].size(); j++) {
                indeg[adj[node][j]]--;
                if (!indeg[adj[node][j]]) {
                    q.push(adj[node][j]);
                }
            }
        }

        return count == N;
    }
};