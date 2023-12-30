class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> hm;
        for (int i = 0 ; i < words.size() ; i++) {
            for (char& j : words[i]) {
                hm[j]++;
            }
        }

        for (const auto& pairs : hm) {
            if (pairs.second % words.size() != 0) {
                return false;
            }
        }
        return true;
    }
};