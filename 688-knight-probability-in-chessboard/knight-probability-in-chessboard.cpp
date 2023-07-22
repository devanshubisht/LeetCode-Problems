class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) {
            return 1;
        }
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n+1,vector<double> (n+1,-1)));

        double totalMoves =pow(8,k); // Calculate the total possible moves
        double validMoves = dfs(n, row, column, k, dp);
        return validMoves / totalMoves;
    }

    double dfs(int n, int x, int y, int k, vector<vector<vector<double>>> &dp) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            return 0; // Invalid move
        }
        if (k == 0) {
            return 1; // Reached the end with valid moves
        }

        if(dp[k][x][y]!=-1){
            return dp[k][x][y];
        }


        double validMoves = 0;
        validMoves += dfs(n, x + 2, y + 1, k - 1, dp);
        validMoves += dfs(n, x - 2, y + 1, k - 1, dp);
        validMoves += dfs(n, x + 2, y - 1, k - 1, dp);
        validMoves += dfs(n, x - 2, y - 1, k - 1, dp);
        validMoves += dfs(n, x - 1, y + 2, k - 1, dp);
        validMoves += dfs(n, x + 1, y - 2, k - 1, dp);
        validMoves += dfs(n, x - 1, y - 2, k - 1, dp);
        validMoves += dfs(n, x + 1, y + 2, k - 1, dp);

        return dp[k][x][y]=validMoves;
    }
};
