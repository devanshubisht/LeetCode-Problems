class Solution {
    string dfs(int i, string &str, unordered_set<string> &s) {
        if(s.find(str) == s.end()) return str;
        
        str[i] = '1';
        return dfs(i + 1, str, s);
        str[i] = '0';
        return dfs(i + 1, str, s);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        string str(nums.size(), '0');
        return dfs(0, str, s);
    }
};