class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int l = 0;
        int result = nums[0];

        for (int i = 0 ; i < nums.size() ; i ++) {
            while (sum < 0) {
                sum -= nums[l];
                l++;
            }
            sum += nums[i];
            result = max(result, sum);
        }

        return result;
        
    }
};