class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double end_time = 0;
        double waiting_time = 0;

        for (int i = 0 ; i < customers.size() ; i++) {
            if (end_time > customers[i][0]) {
                waiting_time += end_time - customers[i][0];
            }
            waiting_time += customers[i][1];
            if (end_time < customers[i][0]) {
                end_time = customers[i][0];
            }
            end_time += customers[i][1];
        }

        return static_cast<double> (waiting_time) / customers.size();
    }
};