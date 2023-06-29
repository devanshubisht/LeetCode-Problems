#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0)
                {
                    q.push({i, j}); // pair can easily be made like this!
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = row + dirs[i][0];
                int y = col + dirs[i][1];

                if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] != INT_MAX)
                {
                    continue;
                }

                rooms[x][y] = rooms[row][col] + 1; // can just refer to the previous one!
                q.push({x, y});
            }
        }
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
