class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(),gas.end(), 0) < accumulate(cost.begin(),cost.end(), 0)) {
            return -1;
        }
        int i = 0;
        int l = 0;
        int total = 0;
        while ( i < cost.size()) {
            total += gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                l = i + 1;
            }
            i++;
        }
        return l;
    }
};