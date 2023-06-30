class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canWalk(cells, row, col, mid)) {
                ans = mid; // Update current answer so far
                left = mid + 1; // Try to find a larger day
            } else right = mid - 1; // Try to find a smaller day
        }
        return ans;
    }

public: 
    bool canWalk(vector<vector<int>>& cells, int row, int col, int dayAt) {
        vector<vector<int>> grid(row, vector<int>(col, 0)); 
        for (int i = 0; i < dayAt; ++i) grid[cells[i][0]-1][cells[i][1]-1] = 1;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int j = 0; j < col; j++) {
            if (dfs(0, j, grid, row, col, visited)) {
                return true;
            }
        }
        return false;
    }


public:
    bool dfs(int x, int y , vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& visited) {

        if (x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] == 1 || visited[x][y] == 1) {
            return false;
        }
        if (x == row - 1) {
            return true;
        }
        visited[x][y] = 1; // do not change back to 0 to keep it optimised
        bool val = dfs(x - 1, y, matrix, row, col, visited) ||
                   dfs(x + 1, y, matrix, row, col, visited) ||
                   dfs(x, y - 1, matrix, row, col, visited) ||
                   dfs(x, y + 1, matrix, row, col, visited);

        return val;
    }
};

// Time: O(row*col * log(row*col)), where row * col <= 2*10^4 is length of the grid.
// Binary search in range [1...row*col] take log(row*col).
// Each binary search, we need to bfs in the grid to check if it's good or not, bfs takes O(E+V), where E=4*V (because each cells have up to 4 neighbors), so time complexity is O(E+V) = O(4V+V) = O(5V) ~ O(row*col).
// So total time complexity is O(row*col * log(row*col))
// Space: O(row*col)

// FASTER SOLUTION BELOW

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canWalk(cells, row, col, mid)) {
                ans = mid; // Update current answer so far
                left = mid + 1; // Try to find a larger day
            } else right = mid - 1; // Try to find a smaller day
        }
        return ans;
    }

public: 
    bool canWalk(vector<vector<int>>& cells, int row, int col, int dayAt) {
        vector<vector<int>> grid(row, vector<int>(col, 0)); 
        for (int i = 0; i < dayAt; ++i) grid[cells[i][0]-1][cells[i][1]-1] = 1;

        for (int j = 0; j < col; j++) {
            if (dfs(0, j, grid, row, col)) {
                return true;
            }
        }
        return false;
    }


public:
    bool dfs(int x, int y , vector<vector<int>>& matrix, int row, int col) {

        if (x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] != 0) {
            return false;
        }
        if (x == row - 1) {
            return true;
        }
        matrix[x][y] = -1;
        bool val = dfs(x - 1, y, matrix, row, col) ||
                   dfs(x + 1, y, matrix, row, col) ||
                   dfs(x, y - 1, matrix, row, col) ||
                   dfs(x, y + 1, matrix, row, col);

        return val;
    }
};