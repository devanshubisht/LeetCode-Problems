class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> res(cost.size() + 1, 0);

        res[0] = cost[0];
        res[1] = cost[1];

        for(int i = 2; i < cost.size() ; i++) {
            res[i] = cost[i] + min(res[i-1], res[i-2]);
        }
        return min(res[cost.size()-1], res[cost.size() -2]);
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