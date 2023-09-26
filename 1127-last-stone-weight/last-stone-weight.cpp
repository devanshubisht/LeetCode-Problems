class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if (first != second) {
                int dif = first - second;
                pq.push(dif);
            }
        }
        if (pq.size() == 0) {
            return 0;
        } else {
            return pq.top();
        }
    }
};