class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        dfs(nums, temp);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& temp) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0 ; i < nums.size() ; i ++) {
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
                continue;
            }
            temp.push_back(nums[i]);
            dfs(nums, temp);
            temp.pop_back();
        }
    }
};