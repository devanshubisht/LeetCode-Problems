class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>  combination;
        dfs(candidates, target, combination, 0);
        return result;

    }
    void dfs(vector<int>& candidates, int target, vector<int>  &combination, int start) {
        if (target == 0){
            result.push_back(combination);
            return;
        }
        if (target <= 0) {
            return;
        }

        for (int i = start ; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            combination.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], combination, i+1);
            combination.pop_back();
        }        
    }
};