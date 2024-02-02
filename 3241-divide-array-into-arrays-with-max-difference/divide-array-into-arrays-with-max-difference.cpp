class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int i = 0; 
        while (i < nums.size()) {
            vector<int> temp;
            for (int j = i ; j < i + 3 ; j++ ) {
                temp.push_back(nums[j]);
            }
            if (temp[2] - temp[0] > k) {
                return {};
            } else {
                v.push_back(temp);
            }
            i += 3;
        }
        return v;
    }
};