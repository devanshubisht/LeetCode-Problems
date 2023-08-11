class Solution {
public:
    
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size() + 1,vector<int>(amount + 1,-1));
        return dfs(amount, coins, 0);
        
    }

    int dfs(int amount, vector<int>& coins, int index) {
        if (amount == 0) {
            
            return 1;
        } 
        if (amount < 0 || index >= coins.size()) {
            return 0;
        }

        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int ways = 0;
        for (int i = index ; i < coins.size() ; i ++) {
            ways += dfs(amount - coins[i], coins, i);
        }
        return dp[index][amount] = ways;

    }

};