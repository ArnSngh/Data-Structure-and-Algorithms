class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        if (std::accumulate(gas.begin(), gas.end(), 0) < std::accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        
        int tank = 0, idx = 0;

        for (int i = 0; i < gas.size(); ++i) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                idx = i + 1;
            }
        }

        return idx;
    }
};