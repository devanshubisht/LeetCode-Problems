class Solution {
public:
    int longestStrChain(vector<string>& words) {
                std::sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
            return word1.size() < word2.size();
        });
        vector<int> dp (words.size(), 1);
        for (int i = 0; i < words.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(words[i].size() == words[j].size() + 1) {
                    if (check(words[j], words[i])) {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
                else if(words[i].size() + 1 == words[j].size()) {
                    if (check(words[i], words[j])) {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }

    bool check(string& w1, string& w2) { 
        int i = 0;
        int j = 0;
        int size = max(w1.size(), w2.size());
        int diff = 0;
        while (j < size) { 
            
            if (w1[i] == w2[j]) {
                i++;
                j++;
            } else {
                diff++;
                if (diff > 1) {
                    return false;
                }
                j++;
            }
        }
        return true;

    }
};