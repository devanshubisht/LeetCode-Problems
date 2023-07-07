class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0, res = 0; 
        int changes = k;
        for(int i = 0 ; i < answerKey.size(); i++){
            if (answerKey[i] == 'T') {
                changes--;
            }
            while (changes < 0) {
                if (answerKey[l] == 'T') {
                    changes++;
                }
                l++;
            }
            res = max(res, i-l+ 1);
        }
        changes = k;
        l =0;
        for(int i = 0 ; i < answerKey.size(); i++){
            if (answerKey[i] == 'F') {
                changes--;
            }
            while (changes < 0) {
                if (answerKey[l] == 'F') {
                    changes++;
                }
                l++;
            }
            res = max(res, i-l+1);
        }
        return res;
    }
};