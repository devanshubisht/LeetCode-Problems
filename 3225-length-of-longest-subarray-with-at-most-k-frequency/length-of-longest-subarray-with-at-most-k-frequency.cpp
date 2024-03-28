class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0; 
        int r = 0;
        unordered_map<int,int> hm;
        int result = 0;
        while ( r < nums.size()) {
            hm[nums[r]]++;
            while (hm[nums[r]] > k) {
                hm[nums[l]]--;
                l++;
            }
            r++;
            result = max(result, r - l);
        }
        return result;
    }
};