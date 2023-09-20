class Solution {
public:
    vector<vector<string>> result;

    vector<vector<string>> partition(string s) {
        vector<string> currentList;
        dfs(s, currentList, 0);
        return result;
    }

    void dfs(string &s, vector<string>& tempArr, int index) {
        if (index == s.size()) {
            result.push_back(tempArr);
            return; // Add this return statement
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                tempArr.push_back(s.substr(index, i - index + 1));
                dfs(s, tempArr, i + 1);
                tempArr.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};
