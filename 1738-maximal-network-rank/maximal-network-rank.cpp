class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n);
        for (int i = 0 ; i < roads.size() ; i++) {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j<n; j++){
                if (find(graph[i].begin(), graph[i].end(), j) != graph[i].end()) {
                    result = max(result, static_cast<int> (graph[i].size() + graph[j].size() - 1));
                } else {
                    result = max(result, static_cast<int> (graph[i].size() + graph[j].size()));
                }
            }
        }
        return result;
    }
};

// take create an adjacency list! with all the neigbours of the nodes. 
// for loop. take the bfs of each.add to visited. 