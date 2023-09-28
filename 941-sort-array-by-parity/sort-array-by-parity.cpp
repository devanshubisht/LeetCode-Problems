class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;

        while ( l < nums.size() && nums[l] % 2 == 0) {
            l++;
        }

        if (l == nums.size()) {
            return nums;
        }
        int r = l + 1;

        
        while (r < nums.size()) {
            if (nums[r] % 2 == 0) {
                swap(nums[r], nums[l]);
                l++;
            }
            r++;
        }
        return nums;
    }
};

