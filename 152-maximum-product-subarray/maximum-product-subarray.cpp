class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int localMin = 1;
        int localMax = 1;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] == 0 ) {
                localMin = 1;
                localMax = 1;
                result = max(result, nums[i]);
                continue;
            }
            int x = nums[i] * localMax, y = nums[i]*localMin;
            localMin = min(min(nums[i], x) ,y);
            localMax = max(max(nums[i], x) ,y);
            result = max(result, localMax);
        }
        return result;

    }
};