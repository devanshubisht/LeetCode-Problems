class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hm;
        int count = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            hm[s[i]] += 1;
        }
        int highest_odd = 0;
        for (const auto& p : hm) {
            if (p.second % 2 == 0) {
                count += p.second;
            } else {
                count += p.second - 1;
                highest_odd = 1;
            }
        }
        count = count + highest_odd;
        return count;
    }
};