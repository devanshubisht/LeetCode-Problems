class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> hm;
        for (int i = 0 ; i < edges.size() ; ++i) {
            hm[edges[i][1]].push_back(edges[i][0]);
            hm[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool> visited (n, false);
        int count = 0;
        for (int i = 0 ; i < n ; i++) {
            if (!visited[i]) {
                dfs(i, hm, visited);
                count++;
            }
        }
        return count;
    }

    void dfs(int& i , unordered_map<int, vector<int>>&hm , vector<bool>& visited) {
        if (visited[i]) {
            return;
        }
        visited[i] = true;
        for (int j=0 ; j < hm[i].size() ;j++) {
            dfs(hm[i][j], hm, visited);
        }
    }
};