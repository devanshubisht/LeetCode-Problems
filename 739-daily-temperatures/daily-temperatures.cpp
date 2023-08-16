class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        int hottest = 0;
        for (int i = temperatures.size() -1; i >=0; i-- ) {
            if (temperatures[i]>= hottest) {
                hottest = temperatures[i];
                continue;
            }
            int days =  1;
            while (temperatures[i + days] <= temperatures[i]) {
                days += ans[i + days];
            }
            ans[i] = days;
        }
        return ans;
    }
};

// approach -> iterate and add to the stack. if the new index is bigger than the stack (which is ordered, then pop it). pop it 
// and find the difference to know what is the next warmest day difference. keep popping.

// approach is to iteracte backwards. when u iterate backwards, firstly keep track of the hottest day.
// when u hit a non hottest day. compare it to the next day. if next day less, use that day's answer to jump and see if that day is more. 