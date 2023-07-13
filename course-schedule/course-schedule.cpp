class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (int i = 0; i < prerequisites.size(); i++ ) {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<bool> visited(numCourses, false);
    vector<bool> global(numCourses, false);

    for (int i = 0; i < prerequisites.size(); i++) {
        int pre = prerequisites[i][0];
        if (global[pre] == true) { continue; }
        if (dfs(pre, adj, visited, global) == false) {
            return false;
        }
    }
    return true;

}

public:
bool dfs(int curr, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& global) {
    if (visited[curr] == true) {
        return false;
    }

    if (global[curr] == true) {
        return true;
    }

    visited[curr] =true;
    global[curr] =true;
    for (int i = 0; i < adj[curr].size(); i++) {
        if (dfs(adj[curr][i], adj, visited, global) == false) {
            return false;
        };
    }
    visited[curr] = false;
    return true;
}
};