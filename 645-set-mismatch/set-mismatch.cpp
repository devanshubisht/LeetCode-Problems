class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n+1) / 2;
        int actSum = 0;
        unordered_set<int> s;
        int val = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            actSum += nums[i];
            if (s.find(nums[i]) != s.end()) {
                val = nums[i];
            } else {
                s.insert(nums[i]);
            }
        }
        return {val, val + sum - actSum};
    }

};