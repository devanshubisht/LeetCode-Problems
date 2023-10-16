class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> hm;

        int l = 0; 
        int r = 0;

        int result = 0;

        while (r < s.size()) {
            if (hm.count(s[r])>0) {
                while (hm.count(s[r]) > 0) {
                    hm.erase(s[l]);
                    l++;
                }
            }
            hm.insert(s[r]);
            r++;
            result = max(result, r - l);
        }
        return result;
    }
};

// have a set of all the characters so far

// iterate through the string with left and right pointer. the right pointer keeps adding the values to the set 

// once a duplicate hits, [get the result]
//move left pointer till its the same as the right. 