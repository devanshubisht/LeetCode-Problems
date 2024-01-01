class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());

        int result = 0;
        int l = 0;
        int r = 0;
        while(r < s.size() && l < g.size()) {
            if (s[r] >= g[l]) {
                result++;
                r++;
            }
            l
            ++;
        }
        return result;
    }
};