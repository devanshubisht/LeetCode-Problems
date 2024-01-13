class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> hm;

        for (int i = 0 ; i < s.size() ; ++i) {
            hm[s[i]]++;
            hm[t[i]]--;
        }

        int result = 0;

        for (const auto& pairs : hm) {
            if (pairs.second>0) {
                result += pairs.second;
            }
        }
        return result;
    }
};