class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> intersect;
        for (int j = 0 ; j < words[0].size() ; j++) {
            intersect[words[0][j]] += 1;
        }
        
        for (int i = 1 ; i < words.size() ; i++) {
            unordered_map<char,int> new_inter;
            for (int j = 0 ; j < words[i].size() ; j++) {
                if (intersect.count(words[i][j]) == 0) {
                    continue;
                } else {
                    new_inter[words[i][j]] += 1;
                }
            }
            for (auto it = intersect.begin(); it != intersect.end();) {
                if (new_inter.count(it->first) > 0) {
                    it->second = std::min(it->second, new_inter[it->first]);
                    ++it;
                } else {
                    it = intersect.erase(it); // Erase returns the next iterator
                }
            }
        }
        vector<string> result;
        for (const auto& pair : intersect) {
            for (int i = 0 ; i < pair.second ; i++) {
                result.push_back(std::string(1, pair.first));
            }
        }
        return result;
    }
};