class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;

        for (int i = 0 ; i < s.size() ; i++) {
            ch ^= s[i];
        }

        for (int j = 0 ; j < t.size() ; j++) {
            ch ^= t[j];
        }

        return ch;
    }
};