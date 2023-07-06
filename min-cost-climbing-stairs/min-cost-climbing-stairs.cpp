class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        for (int i = cost.size() -3 ; i >= 0; i--) {
            cost[i] += min(cost[i+1], cost[i+2]);
        }
        return min(cost[0], cost[1]);
    }
};
// the dp solution, work from right to left and solve the sub problems (use the memoisation as a method to solve subproblems)
//Below is the recursive idea which can be memoised
//     void dfs(int index, vector<int>& cost, int total, int size) {
//         if (index == size) {
//             res = min(res, total);
//             return;
//         }
//         if (index > size) {
//             return;
//         }
//         if (index == -1) {
//             dfs(index + 1, cost, total, size);
//             dfs(index + 2, cost, total, size);
//             return;
//         }
//         dfs(index + 1, cost, total + cost[index], size);
//         dfs(index + 2, cost, total + cost[index], size);
//     }
// };