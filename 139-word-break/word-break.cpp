class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp (n + 1, 0);
        dp[n] = 1;
        
        for (int i = n -1 ; i>= 0 ; i --) {
            for (int j = 0 ; j < wordDict.size() ; j++) {
                if ((i + wordDict[j].size() <= n) && (wordDict[j] == s.substr(i, wordDict[j].size()))) {
                    dp[i] = dp[i + wordDict[j].size()];
                }
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
    }
};