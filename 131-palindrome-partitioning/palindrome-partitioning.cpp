class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> currentList;
        dfs(s, currentList, 0);
        return result;
        
    }

    void dfs(string s, vector<string>& tempArr, int index) {
        if (index == s.size()) {
            result.push_back(tempArr);
            return;
        }

        for (int i = index ; i < s.size() ; i ++) {
            string temp = s.substr(index, i - index + 1);
            if (isPalindrome(temp)) {
                tempArr.push_back(temp);
                dfs(s, tempArr, i+1);
                tempArr.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int l = 0,r = s.size()-1;
        while(l<r){
            while(l<r && !isalnum(s[l])) l++;
            while(l<r && !isalnum(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
            }
        return true;
    }
};