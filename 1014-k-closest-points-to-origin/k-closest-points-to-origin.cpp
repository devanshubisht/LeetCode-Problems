class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        for (int i = 0; i< points.size(); i++ ) {
            pq.push(points[i]);
        }
        vector<vector<int>> res;
        while (k>0) {
            vector<int> first = pq.top();
            pq.pop();
            res.push_back(first);
            k--;
        }

        return res;
    }

private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        } //if true, no swap.
    };
};