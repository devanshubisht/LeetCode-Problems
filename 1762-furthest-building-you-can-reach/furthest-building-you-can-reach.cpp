class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for (int i = 0 ; i < heights.size() -1 ; i++) {
            if (heights[i] < heights[i+1]) {
                int diff = heights[i+1] - heights[i];
                pq.push(diff);
                if (pq.size() > ladders) {
                    int prevDiff = pq.top();
                    bricks -= prevDiff;
                    pq.pop();
                }
                if (bricks < 0) {
                    return i;
                }
            }
        }
        return heights.size() -1;     
    };
};