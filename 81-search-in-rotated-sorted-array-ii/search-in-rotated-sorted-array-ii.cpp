class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid= (left + right)/2;
            if (nums[mid] == target || nums[left] == target || nums[right] == target) {
                return true;
            }
            if((nums[left] == nums[mid]) && (nums[right] == nums[mid]))
            {
                left++;
                right--;
            }

            
            else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid -1;
                } else if (target < nums[left]) {
                    left = mid + 1;
                } else if (target > nums[mid]) {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid -1;
                }
            }
        }
        return false;
    }
};