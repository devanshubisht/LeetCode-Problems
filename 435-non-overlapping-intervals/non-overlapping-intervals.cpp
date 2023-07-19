class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int prev = intervals[0][1];
        int result = 0;
        
        for (int i = 1 ; i < intervals.size(); i++) {
            if (intervals[i][0] < prev) {
                result++;
                prev = min(intervals[i][1], prev);
            } else {
                prev = intervals[i][1];
            }
        }

        return result;
    }
};