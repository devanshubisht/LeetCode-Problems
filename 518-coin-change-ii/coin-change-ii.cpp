class Solution {
public:
    
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size() + 1,vector<int>(amount + 1,0));
        for (int i = 0 ; i < dp.size(); i ++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < dp.size();i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] = dp[i-1][j];
                if (j - coins[i-1] >= 0) {
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[coins.size()][amount];

    }

};