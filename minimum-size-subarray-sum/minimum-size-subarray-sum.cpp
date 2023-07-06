class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int res = INT_MAX;
        int sum = 0;
        for (int i = 0 ; i < nums.size() ; i++ ) {
            sum += nums[i];
            while (sum >= target) {
                res = min(res, i-l +1);
                sum = sum - nums[l];
                l++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};