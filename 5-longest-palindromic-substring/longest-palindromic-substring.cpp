class Solution {
public:
    string res = "";
    string longestPalindrome(string s) {
        for (int i = 0 ; i < s.size() ; i++) {
            solve(i, i, s);
            solve(i, i + 1, s);
        }
        return res;
        
    }

    void solve(int l , int r, string& s) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        int size = r - l - 1;
        if (size > res.size()) {
            res = s.substr(l + 1, r - l - 1);
        }
    }
};