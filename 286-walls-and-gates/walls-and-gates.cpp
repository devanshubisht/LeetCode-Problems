class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        for (int i = 0 ; i < rooms.size() ; i++) {
            for (int j = 0 ; j < rooms[0].size() ; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        vector<int> dir = {-1,0,1,0,-1};
        int dist = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0 ; i < s; i++) {
                pair<int,int> val = q.front();
                q.pop();
                for (int j = 0 ; j < 4 ; j ++) {
                    int nextX = val.first + dir[j];
                    int nextY = val.second + dir[j+1];
                    if (nextX < 0 || nextX >= rooms.size() || 
                        nextY < 0 || nextY >= rooms[0].size() ||
                        rooms[nextX][nextY] == -1 || rooms[nextX][nextY] != INT_MAX) {
                            continue;
                        }
                    rooms[nextX][nextY] = rooms[val.first][val.second] + 1;
                    q.push({nextX,nextY});
                }
            }
        }
    }
};