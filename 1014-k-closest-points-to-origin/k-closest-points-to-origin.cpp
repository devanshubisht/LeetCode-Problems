class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq (points.begin(), points.end());
        vector<vector<int>> res;
        while (k > 0) {
            vector<int> first = pq.top();
            pq.pop();
            res.push_back(first);
            k--;
        }
        return res;
    }

    class Compare {
    public:
        bool operator()(const vector<int>& p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        } // first to be popped
    };
};
