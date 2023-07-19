class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

        if (intervals.size() <= 1) {
            return intervals;
        }
        vector<int> prev = intervals[0];
        result.push_back(prev);
        for (int i = 1 ; i < intervals.size(); i ++) {
            vector<int> new_interval;
            if (prev[1] >= intervals[i][0]) {
                result.erase(result.end());
                new_interval.push_back(min(prev[0], intervals[i][0]));
                new_interval.push_back(max(prev[1], intervals[i][1]));
                result.push_back(new_interval);
                prev = new_interval;
                continue;
            }  else {
                result.push_back(intervals[i]);
                prev = intervals[i];
            }
        }
        return result;
    }
};