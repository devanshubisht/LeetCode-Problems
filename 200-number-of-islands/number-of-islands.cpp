class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result =0;
        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    result++;
                    eraseMap(grid, i, j);
                }
            }
        }
        return result;
        
    }

    void eraseMap(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] == '0'){
            return;
        }

        grid[x][y] = '0';
        vector<int> dir = {-1,0,1,0,-1};

        for (int k = 0 ; k < 4 ; k++) {

            if (x+dir[k] >=0 && x+dir[k] < grid.size() && y+dir[k+1] >= 0 && y+dir[k+1] < grid[0].size() 
                && grid[x+dir[k]][y+dir[k+1]] == '1') {
                eraseMap(grid, x+dir[k], y + dir[k+1]);
            }
        }
    }
};