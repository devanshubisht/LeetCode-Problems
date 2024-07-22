class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        for (int i = 0; i < names.size(); i++) {
            v.push_back({heights[i], names[i]});
        }
        sort(v.begin(), v.end(), [](auto first, auto second) {
            return first.first > second.first;
        });
        vector<string> sortedNames;
        for (const auto& p : v) {
            sortedNames.push_back(p.second);
        }
        return sortedNames;
    }
};
