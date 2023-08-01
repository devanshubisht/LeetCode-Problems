class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> numbers(n);
        for (int i = 0 ; i < n; i++) {
            numbers[i] = i + 1;
        }
        vector<int>t;
        dfs(k,numbers, t, 0);
        return result;
        
    }
    void dfs(int k, vector<int> numbers, vector<int> t, int i) {
        if (t.size() == k) {
            result.push_back(t);
            return;
        }
        for (; i < numbers.size(); i++) {
            t.push_back(numbers[i]);
            dfs(k, numbers, t, i + 1);
            t.pop_back();
        }
    }
};