class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp (coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0 ; i <= amount ; i++) {
            dp[coins.size()][i] = 0;
        }
        for (int i = 0 ; i < dp.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = coins.size() - 1 ; i >= 0 ; i--) {
            for (int j = 1 ; j <= amount ; j++) {
                if (coins[i] <= j) {
                    dp[i][j] += dp[i][j - coins[i]] + dp[i+1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }

            }
        }
        return dp[0][amount];
    }

};