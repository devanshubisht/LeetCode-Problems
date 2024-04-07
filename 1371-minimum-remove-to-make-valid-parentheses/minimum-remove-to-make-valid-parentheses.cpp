class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        stack<int> par;
        unordered_set<int> paired;
        for (int i = 0 ; i < s.size() ; i++) {
            if ((s[i] == ')') && (!par.empty()) && (s[par.top()] == '(') ) {
                int index = par.top();
                par.pop();
                paired.insert(index);
                paired.insert(i);
                continue;
            }
            if (s[i] == '(') {
                par.push(i);
                continue;
            }
        }

        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '(' || s[i] == ')') {
                if (paired.count(i) > 0) {
                    result.push_back(s[i]);
                }
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};