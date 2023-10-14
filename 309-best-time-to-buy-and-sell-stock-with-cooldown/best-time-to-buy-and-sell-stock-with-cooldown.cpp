class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp (2, vector<int> (prices.size(), -1));
        dfs(dp, 0, 1, prices);
        return max(dp[0][0], dp[1][0]);
        //top down returns the answer in the first !!
    }

    int dfs(vector<vector<int>>& dp, int index, int canBuy, vector<int>& prices) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp[canBuy][index] != -1) {
            return dp[canBuy][index];
        }

        if (canBuy) {
            int hold = 0 + dfs(dp, index + 1, canBuy, prices);
            int buy = dfs(dp, index + 1, !canBuy, prices) - prices[index];
            dp[canBuy][index] = max(hold,buy);
        } else {
            int hold = 0 + dfs(dp, index + 1, canBuy, prices);
            int sell = prices[index] + dfs(dp, index + 2, !canBuy, prices);
            dp[canBuy][index] = max(hold,sell);
        }
        return dp[canBuy][index];
    }
};