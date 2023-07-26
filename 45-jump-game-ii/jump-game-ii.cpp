class Solution {
public:
    int jump(vector<int>& nums) {
        int reachable = 0;
        int count = 0;
        int s = nums.size();
        int prev = 0;
        for (int i = 0 ; i < s -1 ; i++) {
            reachable = max(reachable, nums[i] + i);
            if (i == prev) {
                prev = reachable;
                count++;
            }
        }
        return count ;
    }
};