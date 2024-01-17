class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hm;
        for (int i = 0 ; i < arr.size() ; i++) {
            hm[arr[i]]++;
        }
        unordered_set<int> s;
        for (const auto& vals : hm) {
            if (s.count(vals.second) > 0 ) {
                return false;
            }
            s.insert(vals.second);
        }
        return true;
        
    }
};