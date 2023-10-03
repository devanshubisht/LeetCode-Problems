class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> hm;
        vector<int> visited(numCourses, -1);
        vector<int> total_visisted(numCourses, -1);
        for (int i = 0 ; i < prerequisites.size(); i++) {
            hm[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i =0 ; i < numCourses; i++) {
            if (total_visisted[i] == -1 && !dfs(hm, i, visited, total_visisted)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& hm, int node, vector<int>& visited,vector<int>& total_visited) {
        if (visited[node] != -1) {
            return false;
        }
        if (total_visited[node] == 1) {
            return true;
        }

        visited[node] = 1; 
        total_visited[node] = true;

        for (int i = 0 ; i < hm[node].size() ; i++ ) {
            if (!dfs(hm,hm[node][i], visited,total_visited )) {
                return false;
            }
        }
        visited[node] = -1;
        return true;
    }
};



// for dfs! -> go all the 