class Solution {
public:
    const int mod = (int)pow(10, 9) + 7; 
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> vec(target + 1, vector<int>(n + 1, -1));

        recurse(n, k ,target, vec);
        return vec[target][n];
    }

    int recurse(int n , int k , int target, vector<vector<int>>& dp) {
        if (target == 0 && n == 0) {
            return 1;
        }
        if (target <= 0 || n <= 0) {
            return 0;
        }

        if (dp[target][n] != -1) {
            return dp[target][n];
        }

        int ways = 0;
        for (int i = 1 ; i <= k ; i++) {
            ways = (ways + (recurse(n - 1, k, target - i, dp)) % mod ) % mod; 
        }
        dp[target][n] = ways;
        return ways;
    }
};