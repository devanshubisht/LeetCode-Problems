class Solution {
public:
    int res = 0;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> bMap(n, 0);
        for (int i = 0; i < n; i++) {
            bMap[i] = 0;
        }

        dfs(0, bMap, 0, requests);
        return res;
        
    }

    void dfs(int index, vector<int>& bMap, int accepted, vector<vector<int>>& requests){ 
        if (index == requests.size()) {
            for (int i = 0 ; i < bMap.size() ; i++)  {
                if (bMap[i] != 0){
                    return;
                }
            }
            res = max(res, accepted);
            return;
        }
        int out = requests[index][0];
        int in = requests[index][1];
        bMap[out]--;
        bMap[in]++;
        accepted++;
        dfs(index + 1, bMap, accepted, requests);
        bMap[out]++;
        bMap[in]--;
        accepted--;
        dfs(index + 1, bMap, accepted, requests);
    }
};
