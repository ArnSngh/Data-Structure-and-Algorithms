class Solution {
public:

    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int>& color)
    {
        color[node] = c;

        for(int i = 0; i < graph[node].size(); i++)
        {
            int neby = graph[node][i];

            if(color[neby] == c)
            {
                return false;
            }

            if(color[neby] == -1)
            {
                if(dfs(neby, 1 - c, graph, color) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int v = graph.size();
        vector<int> color(v, -1);

        for(int i = 0; i < v; i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i, 1, graph, color) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};