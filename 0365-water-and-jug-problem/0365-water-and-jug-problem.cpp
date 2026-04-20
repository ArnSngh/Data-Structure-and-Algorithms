class Solution {
public:
    vector<pair<int, int>> genNeighbors(pair<int, int> node, int x, int y) {
        int a = node.first;
        int b = node.second;

        vector<pair<int, int>> neighbors;

        // Fill either jug
        neighbors.push_back({x, b});
        neighbors.push_back({a, y});

        // Empty either jug
        neighbors.push_back({0, b});
        neighbors.push_back({a, 0});

        // Pour X -> Y
        int pourToY = min(a, y - b);
        neighbors.push_back({a - pourToY, b + pourToY});

        // Pour Y -> X
        int pourToX = min(b, x - a);
        neighbors.push_back({a + pourToX, b - pourToX});

        return neighbors;
    }

    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (target == 0) return true;

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;

        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int a = current.first;
            int b = current.second;

            if (a == target || b == target || a + b == target) {
                return true;
            }

            auto neighbors = genNeighbors(current, x, y);

            for (auto& neighbor : neighbors) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};