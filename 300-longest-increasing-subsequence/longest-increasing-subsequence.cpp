class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result (nums.size(), 1);
        for (int i = 0 ; i < nums.size() ; i++) {
            for (int j = 0 ; j < i ; j++) {
                if (nums[i] > nums[j]) {
                    result[i]= max(result[i], 1 + result[j]);
                }
            }
        }
        return *max_element(result.begin(), result.end());
    }
};