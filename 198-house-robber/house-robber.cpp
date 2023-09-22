class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size() == 1 ? nums[0] : max(nums[0], nums[1]);
        }

        nums.insert(nums.begin(), 0);
        
        for (int i = 2; i < nums.size(); i++) {
            int robCurrent = nums[i] + nums[i-2];
            int skipCurrent = nums[i-1];
            
            nums[i] = max(robCurrent, skipCurrent);
        }
        
        return nums[nums.size()-1];
    }
};
