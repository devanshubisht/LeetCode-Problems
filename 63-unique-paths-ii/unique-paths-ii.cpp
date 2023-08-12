class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        int val = 1;
        for (int i =0 ; i < obstacleGrid.size(); i++) {
            if(obstacleGrid[i][0] == 1) {
                val = 0;
            } 
            dp[i][0] = val;
        }
        val = 1;
        for (int j =0 ; j < obstacleGrid[0].size(); j++) {
            if (obstacleGrid[0][j] == 1) {
                val = 0;
            } 
            dp[0][j] = val;
            
        }

        for (int i = 1 ; i < obstacleGrid.size(); i++) {
            for (int j = 1 ; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];

    }
};