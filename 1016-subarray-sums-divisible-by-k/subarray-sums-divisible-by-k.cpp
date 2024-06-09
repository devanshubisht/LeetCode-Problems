class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> hm;
        int prefSum = 0;
        hm[0] = 1;
        for (int i = 0 ; i < nums.size() ; i++) {
            prefSum += nums[i];
            int sum = prefSum % k;
            if (sum < 0) {
                sum += k;
            }
            if (hm.find(sum) != hm.end()) {
                count += hm[sum];
                hm[sum]++;
            } else {
                hm[sum] = 1;
            }
        }
        return count;
    }
};

