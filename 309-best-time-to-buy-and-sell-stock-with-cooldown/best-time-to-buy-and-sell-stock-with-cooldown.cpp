class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp (2, vector<int> (prices.size(), -1));
        dfs(dp, 0, 1, prices);
        return max(dp[0][0], dp[1][0]);
        //top down returns the answer in the first !!
    }

    int dfs(vector<vector<int>>& dp, int index, int canbuy, vector<int>& prices){
        if (index >= prices.size() ) {
            return 0;
        }

        if (dp[canbuy][index]!= -1) {
            return dp[canbuy][index];
        }

        if (canbuy) {
            int buying = dfs(dp, index +1, 0, prices) - prices[index];
            int hold = dfs(dp, index + 1, canbuy, prices);
            dp[canbuy][index] = max(buying, hold);

        } else {
            int selling = dfs(dp, index + 2, 1, prices) + prices[index] ;
            int hold = dfs(dp, index + 1, canbuy, prices);
            dp[canbuy][index] = max(selling, hold);
        }
        return dp[canbuy][index];
    }
};