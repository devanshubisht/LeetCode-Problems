class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size(), 0);
        vector<int> rightProduct(nums.size(), 0);
        
        leftProduct[0] = nums[0];

        for (int i = 1 ; i < nums.size() ; i++) {
            leftProduct[i] = nums[i] * leftProduct[i-1];
        }

        rightProduct[nums.size() - 1] = *(nums.end() - 1);
        
        for (int i = nums.size() - 2 ; i >= 0 ; i--) {
            rightProduct[i] = nums[i] * rightProduct[i+1];
        }

        vector<int> finalProduct(nums.size(), 0);

        for (int i = 0; i < nums.size() ; i++) {
            if (i == 0) {
                finalProduct[i] = rightProduct[i+1];
            } else if (i == nums.size() - 1) {
                finalProduct[i] = leftProduct[i-1];
            } else {
                finalProduct[i] = leftProduct[i-1] * rightProduct[i+1];
            }
        }
        return finalProduct;
        
    }
};