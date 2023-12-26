class Solution {
public:
    // bool check(unordered_map<int,bool>& charT) {
    //     for (const auto& val : charT) {
    //         if (val.second == false) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    string minWindow(string s, string t) {
        unordered_map<char, int> hm;
        for (const char& a : t) {
            hm[a]++;
        }
        int val = hm.size();
        unordered_map<char,int> charS;
        int l = 0; 
        int r = 0;
        int size = s.size();
        int curVal = 0;
        string curResult = "";
        string globalResult = s;
        bool done = false;

        while (r < size) {
            charS[s[r]]++;
            if (hm.count(s[r]) > 0) {
                if (hm[s[r]] == charS[s[r]]) {
                    curVal += 1;
                }
            }
            while (curVal == val && l <= r) {
                charS[s[l]]--;
                if ((hm.count(s[l]) > 0) && (charS[s[l]] < hm[s[l]])) {
                    if (r - l + 1 <= globalResult.size()) {
                            globalResult = s.substr(l, r - l + 1);
                            done = true;
                    }
                    curVal--;
                }
                l++;
            }
            r++;
        }
        if (done) {
            return globalResult;
        } else {
            return "";
        }
    }
};

// make a hashmap with t , value is if it has been included
// have a hash map to track what is in the string s, value is the number.
// once there is a match, reduce from the left and see if any of the valye decreases