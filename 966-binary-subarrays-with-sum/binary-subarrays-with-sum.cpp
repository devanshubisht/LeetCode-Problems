class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> hm;
        int prefix = 0;
        int result = 0;
        hm[0] = 1;
        for (int i = 0; i < nums.size() ; i++) {
            prefix += nums[i];
            if (hm.find(prefix - goal) != hm.end()) {
                result+= hm[prefix-goal];
            }
            hm[prefix]++;
        }
        return result;
    }
};