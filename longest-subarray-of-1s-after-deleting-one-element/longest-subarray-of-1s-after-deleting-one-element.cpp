class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> results; 
        int res = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] == 0) {
                results.push_back(res);
                res = 0;
                continue;
            }

            res++;

            if (i == nums.size() -1 ) {
                results.push_back(res);
            }
        }
        if (results.size() == 1 ) {
            return nums.size() -1;
        }
        int finals = 0;
        for (int i = 0 ; i < results.size() - 1 ; i++) {
            finals = max(results[i] + results[i+1], finals) ;
        }
        return finals;
    }
};