class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int l = 0;
        unordered_map<int,int> hm;
        for (int i = 0 ; i < s.size() ; i++) {
            hm[s[i]]++;
        }
        int r = 0;
        while (r < goal.size()) {
            if (goal[r] == s[l]) {
                int initial_r = r;
                while (goal[r] == s[l]) {
                    l++;
                    r = (1 + r) % goal.size();    
                    if (l == s.size()) {
                        return true;
                    }
                }
                l = 0;
                hm[s[0]] -= 1;
                if (hm[s[0]] == 0) {
                    return false;
                }
                r = (1 + initial_r) % goal.size();
            } else {
                r++;
            }
        }
        return false;
    }
};