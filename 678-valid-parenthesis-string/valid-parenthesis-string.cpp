class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0; // represents the min number of OPEN [still left to be paired] '(' brackets at any index
        int cmax = 0; // represents the max number of OPEN '(' brackets at any index

        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '(') {
                cmin++;
                cmax++;
            }
            if (s[i] == ')') {
                cmin--;
                cmax--;
            }
            if (s[i] == '*') {
                cmin--; // assume * is )
                cmax++; // assume * is (
            }
            if (cmax < 0 ) {
                return false;
            }
            if (cmin < 0) {
                cmin = 0; // some of the * which was turned to ) will be turned to ""
            }
        }

        return cmin == 0;
    }
};