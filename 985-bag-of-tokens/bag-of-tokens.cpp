class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size() -1;
        int score = 0;
        int maxScore = 0;
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                l++;
                score +=1;
                maxScore = max(maxScore,score);
                continue;
            } else {
                if (score >= 1) {
                    power += tokens[r];
                    r--;
                    score-=1;
                    maxScore = max(maxScore,score);
                    continue;
                }
            }
            break;
        }
        return maxScore;
    }
};