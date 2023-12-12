class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir {-1, 0, 1, 0, -1};
        queue<pair<int,int>> q;

        for (int i = 0 ; i < grid.size() ; ++i) {
            for (int j = 0 ; j < grid[0].size() ; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        int result = 0;

        while (!q.empty()) {
            int len = q.size();
            for (int i =0 ; i < len ; i++) {
                auto orange = q.front();
                q.pop();
                int x = orange.first;
                int y = orange.second;
                for (int j = 0 ; j < 4 ; ++j) {
                    int nxX = x + dir[j];
                    int nxY = y + dir[j+1];
                    if (nxX < 0 || nxX >= grid.size() || nxY < 0 || nxY >= grid[0].size() || grid[nxX][nxY] != 1) {
                        continue;
                    }
                    q.push({nxX, nxY});
                    grid[nxX][nxY] = 2;
                }
            }
            if (!q.empty()) {
                result++;
            }
        }

        for (int i = 0 ; i < grid.size() ; ++i) {
            for (int j = 0 ; j < grid[0].size() ; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return result;
    }
};