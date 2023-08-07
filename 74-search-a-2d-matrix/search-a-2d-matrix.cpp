class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false; }
        int left = 0;
        int right = matrix.size() - 1;
        int boundary = matrix[0].size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] > target) {
                right = mid -1;
            } else if (matrix[mid][boundary -1 ] < target) {
                left = mid + 1;
            } else {
                int l = 0;
                int r = matrix[mid].size() - 1;
                while (l <= r) {
                    int m = (l + r)/2;
                    if (matrix[mid][m] < target) {
                        l = m + 1;
                    } else if (matrix[mid][m] > target ) {
                        r = m - 1;
                    } else {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};