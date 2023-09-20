class Solution {
public:
    vector<string> result;
    unordered_map<char, string> hm;

    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        hm['2'] = "abc";
        hm['3'] = "def";
        hm['4'] = "ghi";
        hm['5'] = "jkl";
        hm['6'] = "mno";
        hm['7'] = "pqrs";
        hm['8'] = "tuv";
        hm['9'] = "wxyz";
        string temp;
        dfs(temp, 0, digits);
        return result;
        
    }

    void dfs(string& temp, int i,  string digits) {
        if (i == digits.size()) {
            result.push_back(temp);
            return;
        }
    
        for(auto val: hm[digits[i]]) {
            temp.push_back(val);
            dfs(temp, i + 1,   digits);
            temp.pop_back();
        }
    }
};