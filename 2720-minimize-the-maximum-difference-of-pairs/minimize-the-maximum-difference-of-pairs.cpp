class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size() -1] - nums[0];
        
        while (low <= high) {
            int mid = (low + high)/2;
            if (can_form_pairs(nums, mid, p)) {
                high = mid - 1;
            } else {
                low= mid + 1;
            }
        }
        return low;

    }

        bool can_form_pairs(const std::vector<int>& nums, int mid, int p) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1 && count < p;) {
            if (nums[i+1] - nums[i] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= p;
    }
};