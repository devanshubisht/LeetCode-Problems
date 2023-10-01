class Solution {
public:
    string reverseWords(string s) {
        string newWords;
        int prev = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == ' ') {
                newWords += reverseWord(s.substr(prev, i - prev)) + " ";
                prev = i+1;
            }
        }
        newWords += reverseWord(s.substr(prev, s.size() - prev));
        return newWords;
        
    }

    string reverseWord(string s) {
        string newWord;
        for (int i = s.size() - 1; i>= 0 ; i--) {
            newWord.push_back(s[i]);
        }
        return newWord;
    }
};