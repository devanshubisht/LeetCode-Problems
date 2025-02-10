class Solution {
public:
    string clearDigits(string s) {
        int x = s.size();
        int cur = 0;
        while (cur < x) {
            if (isdigit(s[cur])) {
                s.erase(cur, 1);
                s.erase(cur-1, 1);
                x-=2;
                cur--;
            } else {
                cur++;
            }
        }
        return s;
    }
};