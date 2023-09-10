class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> visited(n + 1);
        unordered_map<int, vector<pair<int,int>>> hm;
        for (int i = 0; i < times.size(); i ++) {
            hm[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> maxHeap;

        maxHeap.push({0, k});
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while (!maxHeap.empty()) {
            pair<int, int> first = maxHeap.top();
            maxHeap.pop();
            visited[first.second] = true;
            for(int i = 0 ; i < hm[first.second].size(); i++) {
                int v = hm[first.second][i].first;
                int weight = hm[first.second][i].second;
                if (visited[v] == false && dist[v] > dist[first.second] + weight) {
                    dist[v] = dist[first.second] + weight;
                    maxHeap.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<dist.size();i++){
            ans = max(ans, dist[i]);
        }
        if(ans==1e9) return -1;
        return ans;
    }

};