class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size() == 1 ? nums[0] : max(nums[0], nums[1]);
        }
        
        int n = nums.size();
        nums.push_back(0);
        
        for (int i = n - 3; i >= 0; i--) {
            int robCurrent = nums[i] + nums[i+2];
            int skipCurrent = nums[i+1];
            int robNext = nums[i] + nums[i+3];
            
            nums[i] = max(robCurrent, max(skipCurrent, robNext));
        }
        
        return nums[0];
    }
};
