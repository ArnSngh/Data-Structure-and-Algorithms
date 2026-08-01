class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int index = 0; index < prerequisites.size(); index++) {

            int course = prerequisites[index][0];
            int precourse = prerequisites[index][1];

            adjlist[precourse].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completedCourses = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            completedCourses++;

            for (int i = 0; i < adjlist[node].size(); i++) {

                int neighbour = adjlist[node][i];

                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return completedCourses == numCourses;
    }
};