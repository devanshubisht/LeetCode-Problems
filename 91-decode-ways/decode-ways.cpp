class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp (s.size(), -1);
        return dfs(0 , s, dp);
    }

    int dfs(int i, string& s, vector<int>& dp) {
        if (i >= s.size() - 1) {
            if (s[i] == '0') {
                return 0;
            }
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int small = s[i] - '0';

        int larger = stoi(s.substr(i, 2));

        if (small == 0 ) {
            return 0;
        }
        int val;
        if  (larger > 26) {
            val = dfs(i + 1, s, dp);
        } else {
            val = dfs(i + 1, s, dp) + dfs(i + 2, s , dp);
        }

        dp[i] = val;
        return val;
    }
};

// loop thru. take 1 or 2 and dfs. if u find a 0 as ur starting. return. if ur 2 letters together bigger than 26. return.

// memoise with the 1d-dp containing the number of ways. at that index, highest amount.