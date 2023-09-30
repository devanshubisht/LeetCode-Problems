class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> minValues;
        stack<int> st;

        int minValue = nums[0];
        for (int i = 0 ; i < nums.size() ; i++) {
            minValue = min(minValue,nums[i]);
            minValues.push_back(minValue);
        }

        st.push(nums[nums.size() -1]);
        for (int k = nums.size() - 2 ; k >= 0; k-- ) {
            if ((nums[k] > minValues[k])) {
                while (!st.empty() && nums[k] > st.top()) {
                    if ( st.top() > minValues[k]) {
                        return true;
                    }
                    st.pop();
                }
            }
            st.push(nums[k]);
        }
        return false;
    }
};