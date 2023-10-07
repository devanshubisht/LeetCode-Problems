class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        std::stack<int> st;

        int maxArea = 0;

        for (int i = 0 ; i < heights.size() ; i++) {
            while (!st.empty() && (heights[st.top()] > heights[i])) {
                int index = st.top();
                int height = heights[index];
                st.pop();
                if (st.empty()) {
                    index = -1;
                } else {
                    index = st.top();
                }
                maxArea = max(maxArea, height * (i - index -1));
            }
            st.push(i);
        }

        return maxArea;
    }
};

// once you hit a decreasing value. pop it back and compare the max area from that pt to the index before decreasing value.

// store the index instead.