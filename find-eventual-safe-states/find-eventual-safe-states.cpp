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
            if (dfs(terminal , i , visited, graph, global, cycle)) {
                result.push_back(i);
            }
        }
        return result;
    }

    bool dfs(vector<int>& terminal, int node, vector<int>& visited, vector<vector<int>>& graph, vector<int>& global, set<int>& cycle) {
        if (visited[node] == 1 || cycle.find(node) != cycle.end()) {
            cycle.insert(node);
            return false;
        }

        if (global[node] == 1 ) { 
            return true;
        }

        for (int i =0 ; i < terminal.size() ; i ++) {
            if (terminal[i] == node) {
                return true;
            }
        }
        visited[node] = 1;
        global[node] = 1;
        for (int i = 0 ; i < graph[node].size() ; i ++) {
            if (!dfs(terminal, graph[node][i], visited, graph, global,  cycle)) {
                cycle.insert(node);
                visited[node] = -1;
                global[node] = -1;
                return false;
            }
        }
        visited[node] = -1;
        return true;
    }
};