class Solution {
public:
    vector<string> result;
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        dfs(temp, 0, pad, digits);
        
        return result;
    }

    void dfs(string& temp, int i, const vector<string>& pad, const string& digits) {
        if (i == digits.size()) {
            result.push_back(temp);
            return;
        }
        
        int digit = digits[i] - '0';
        const string characters = pad[digit];
        
        for (char ch : characters) {
            temp.push_back(ch);
            dfs(temp, i + 1, pad, digits);
            temp.pop_back();
        }
    }
};
