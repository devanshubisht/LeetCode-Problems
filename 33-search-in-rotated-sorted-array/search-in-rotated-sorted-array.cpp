class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left  = 0; 
        int right = nums.size() -1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (target == nums[mid]) {
                return mid;
            }

            if (nums[mid] >= nums[left]) {
                if (target < nums[left]) {
                    left = mid + 1;
                } else if (target < nums[mid]) {
                    right = mid -1;
                } else if (target > nums[mid]) {
                    left = mid + 1;
                }
            } else {
                if (target < nums[mid]) {
                    right = mid -1;
                } else if (target > nums[right]){
                    right= mid-1;
                } else if (target > nums[mid]) {
                    left = mid +1;
                }
            }
        }
        return -1;
    }
};