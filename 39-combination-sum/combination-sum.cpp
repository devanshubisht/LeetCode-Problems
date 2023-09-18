class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        dfs(candidates, target, combination, 0);
        return result;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int>& combination, int start) {
        if (start > candidates.size()) {
            return;
        }
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        if (target < 0 ) {
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], combination, i);
            combination.pop_back();
        }
    }
};