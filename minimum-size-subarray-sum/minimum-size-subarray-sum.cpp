class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int res = nums.size();
        int sum = 0;
        for (int i = 0 ; i < nums.size() ; i++ ) {
            sum += nums[i];
            while (sum >= target) {
                res = min(res, i-l +1);
                sum = sum - nums[l];
                l++;
            }
        }
        if (sum<target && l == 0) {
            return 0;
        }
        return res;
        
    }
};