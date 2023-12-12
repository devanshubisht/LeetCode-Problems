class Solution {
public:
    string removeOccurrences(string s, string part) {
        for (int i = 0 ; i < s.size() ; ++i) {
            if (s[i] == part[0]) {   
                if (s.substr(i, part.size()) == part) {
                    string val = s.substr(0, i) + s.substr(i + part.size(), s.size() - i - part.size() + 1);
                    return removeOccurrences(val, part);
                }
            }
        }
        return s;
    }
};