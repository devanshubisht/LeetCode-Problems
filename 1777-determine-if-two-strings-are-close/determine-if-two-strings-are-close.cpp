class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1 (26, 0);
        vector<int> freq2 (26, 0);
        unordered_set<char> hm1;
        unordered_set<char> hm2;
        if (word1.size() != word2.size()) {
            return false;
        }
        for (int i =0 ; i < word1.size() ; i++) {
            freq1[word1[i] - 'a'] += 1;
            hm1.insert(word1[i]);
            freq2[word2[i] - 'a'] += 1;
            hm2.insert(word2[i]);
        }

        sort(freq1.begin() , freq1.end());
        sort(freq2.begin() , freq2.end());

        if (hm1 == hm2 && freq1 == freq2) {
            return true;
        } else {
            return false;
        }
    }
};