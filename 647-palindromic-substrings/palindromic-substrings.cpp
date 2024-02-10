class Solution {
public:

    int count = 0;
    void solve(string& s, int left, int right) {
        while (left>=0 && right<s.size() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
        
    }
    int countSubstrings(string s) {
        for (int i = 0 ; i < s.size(); i++ ) {
            solve(s, i, i);
            solve(s, i, i+1);
        }
        return count;
        
    }
};