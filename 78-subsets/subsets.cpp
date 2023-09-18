class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(nums, 0, temp);
        return result;
    }

    void dfs(vector<int>& nums, int i, vector<int>& res) {
        result.push_back(res);    
        for (int j = i; j < nums.size(); j++) {
            res.push_back(nums[j]);
            dfs(nums, j+1, res);
            res.pop_back();
        }
        
    }

};