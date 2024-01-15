class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto sorter = [](const vector<int>& p, const vector<int>& q)  {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(sorter)> pq (points.begin(), points.end());
        vector<vector<int>> res;
        while (k>0) {
            vector<int> first = pq.top();
            pq.pop();
            res.push_back(first);
            k--;
        }
        return res;
    }
};