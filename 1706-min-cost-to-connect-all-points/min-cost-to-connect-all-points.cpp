class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // use prims algo 
        int n = points.size();
        std::priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

        vector<int> visited (points.size());
        int result = 0;

        int connected = 0;
        visited[0] = 1;
        for(int i = 1 ; i < points.size(); i++) {
            int dist = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
            min_heap.push({dist,i});
        }
        while (connected < points.size() -1) {
            pair<int,int> val = min_heap.top();
            min_heap.pop();
            int dist = val.first;
            int i = val.second;
            if (visited[i] == 1) {
                continue;
            }
            printf("dist : %d and %d \n", dist, i);
            visited[i] = 1;
            result += dist;
            connected++;
            for(int j = 0  ; j < points.size(); j++) {
                if (!visited[j]){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                min_heap.push({dist,j});
                }
            }
        }

        return result;

    }
};