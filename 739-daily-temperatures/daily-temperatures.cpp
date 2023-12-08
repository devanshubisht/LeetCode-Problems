class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        int hottest = 0;
        stack<pair<int,int>> st;
        for (int i = 0; i < temperatures.size(); i++ ) {
            if (st.empty() || st.top().first >= temperatures[i]) {
                st.push({temperatures[i], i});
            } else {
                while (!st.empty() && st.top().first < temperatures[i]) {
                    pair<int,int> top = st.top();
                    st.pop();
                    ans[top.second] = i - top.second;
                }
                st.push({temperatures[i], i});
            }
        }
        while (!st.empty()) {
            pair<int,int> top = st.top();
            st.pop();
            ans[top.second] = 0;
        }
        return ans;
    }
};

// approach -> iterate and add to the stack. if the new index is bigger than the stack (which is ordered, then pop it). pop it 
// and find the difference to know what is the next warmest day difference. keep popping.

// approach is to iteracte backwards. when u iterate backwards, firstly keep track of the hottest day.
// when u hit a non hottest day. compare it to the next day. if next day less, use that day's answer to jump and see if that day is more. 
// for this approach, when u go to the next day. if smaller. u take the answer of that day and then u add it to the days being tracked from that day.