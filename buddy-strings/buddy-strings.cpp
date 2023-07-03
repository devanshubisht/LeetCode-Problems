class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        vector<int> val;
        unordered_map<int,int> count;
        for (int k = 0 ; k < s.size() ; k++) {
            if (s[k] != goal[k]) {
                val.push_back(k);
            }
            count[s[k]]++;
        }
        if (s == goal) {
            for (int i = 0 ; i < s.size(); i++) {
                if (count[s[i]]>1) {
                    return true;
                }
            }
        }

        if (val.size() == 2) {
            if ((s[val[0]] == goal[val[1]]) && s[val[1]] == goal[val[0]]) {
                return true;
            }
        }
        return false;
    }
};