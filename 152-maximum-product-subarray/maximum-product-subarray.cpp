class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minSoFar = 1;
        int maxSoFar = 1;

        int result = nums[0];
        for(int i = 0 ; i < nums.size(); i++) {
            if (nums[i] == 0) {
                minSoFar = 1;
                maxSoFar = 1;
                result = max(result, nums[i]);
                continue;
            }
            int x = minSoFar * nums[i];
            int y = maxSoFar * nums[i];
            minSoFar = min(min(x, nums[i]),y);
            maxSoFar = max(max(x, nums[i]),y);
            result = max(result,maxSoFar);
        }
        return result;
    }
};