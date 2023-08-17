class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < row; i++ ) {
            for (int j = 0 ; j< col; j++) {
                if (mat[i][j] == 0) {
                    q.push({i,j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        while (!q.empty()) {
            for (int z = 0 ; z < q.size(); z ++) {
                pair<int, int> val = q.front();
                int x = val.first;
                int y = val.second;
                q.pop();
                for (int i = 0 ; i < 4 ; i ++) {
                    int nx = x + DIR[i];
                    int ny = y + DIR[i+1];
                    if (nx >= 0 && nx< row && ny >= 0 && ny < col && mat[nx][ny] == -1 ) {
                        mat[nx][ny] = mat[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return mat;
    }
};

// approach

// do bfs from the 1s. the 0s are are already done 
// if 1. do bfs for it such that.
// once the value is 0 then break already. and store that level
// 