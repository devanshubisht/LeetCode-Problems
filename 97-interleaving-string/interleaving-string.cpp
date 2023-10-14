class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> v (s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dfs(s1, 0, s2, 0, s3, 0, v);
    }
    bool dfs(string s1, int s1i, string s2, int s2i, string s3, int s3i, vector<vector<int>>& v) {

        if (s1i == s1.size() && s2i == s2.size()) {
            if (s3i == s3.size()) {
            return true;
        }
            return false;
        }

        if (v[s1i][s2i] != -1) {
            return v[s1i][s2i];
        }
        bool ans = false;

        if (s1i < s1.size() && s1[s1i] == s3[s3i]) {
            ans |= dfs(s1, s1i + 1, s2, s2i, s3, s3i + 1, v);
        } 
        if (s2i < s2.size() && s2[s2i] == s3[s3i]) {
            ans |= dfs(s1, s1i , s2, s2i + 1, s3, s3i + 1, v);
        } 
        v[s1i][s2i] = ans;
        return v[s1i][s2i];
    }
};