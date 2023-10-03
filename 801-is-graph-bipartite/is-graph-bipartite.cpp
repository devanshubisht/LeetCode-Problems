class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i =0 ; i < graph.size() ; i++) {
            if (color[i] == -1 && !dfs(color, graph, 0, i)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<int>& color, vector<vector<int>>& graph, int isEven, int node) {
        if (color[node] != -1) {
            return color[node] == isEven;
        }
        color[node] = isEven;
        for (int i = 0 ; i < graph[node].size() ; i++) {
            if (!dfs(color, graph, !isEven, graph[node][i])) {
                return false;
            }
        }
        return true;

    }
};


// biparite if the cycle is odd length and not even