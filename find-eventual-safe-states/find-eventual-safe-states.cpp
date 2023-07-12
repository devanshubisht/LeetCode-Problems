class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> terminal;
        for (int i = 0 ; i < graph.size() ; i++) {
            if (graph[i].size() == 0) {
                terminal.push_back(i);
            }
        }
        vector<int> result;
        vector<int> visited (graph.size(), -1);
        vector<int> global (graph.size(), -1);
        set<int> cycle;

        for (int i = 0 ; i < graph.size() ; i++) {
            if (visited[i] != 1) {
                dfs(i, visited, graph, global);
            }
        }
        for (int i = 0 ; i < global.size() ; i ++) {
            if (global[i] == 1){
                result.push_back(i);
            }
        }
        return result;
        
    }

    bool dfs(int node, vector<int>& visited, vector<vector<int>>& graph, vector<int>& global) {
        if (visited[node] == 1) {
            return false;
        }

        if (global[node] == 1 ) { 
            return true;
        }

        visited[node] = 1;
        global[node] = 1;
        for (int i = 0 ; i < graph[node].size() ; i ++) {
            if (!dfs(graph[node][i], visited, graph, global)) {
                global[node] = -1;
                return false;
            }
        }
        visited[node] = -1;
        return true;
    }
};