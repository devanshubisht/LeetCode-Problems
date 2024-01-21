class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1 ; i < matrix.size() ; i++) {
            for (int j = 0 ; j < matrix[0].size() ; j++) {
                int top = matrix[i][j] + matrix[i - 1][j];
                if (j == 0) {
                    int topright = matrix[i][j] + matrix[i-1][j+1];
                    matrix[i][j] = min(top, topright);
                } else if (j == matrix[0].size() - 1) {
                    int topleft = matrix[i][j] + matrix[i-1][j-1];
                    matrix[i][j] = min(top, topleft);
                } else {
                    int topright = matrix[i][j] + matrix[i-1][j+1];
                    int topleft = matrix[i][j] + matrix[i-1][j-1];
                    matrix[i][j] = min(top, topleft);
                    matrix[i][j] = min(matrix[i][j], topright);
                }
            }
        }
        int result = INT_MAX;
        for (int j = 0 ; j < matrix[0].size() ; j++) { 
            result = min(matrix[matrix.size()-1][j], result);
        }
        return result;
    }
};