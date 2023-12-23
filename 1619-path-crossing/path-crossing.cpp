class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> s;
        pair<int,int> p = {0,0};
        s.insert(p);
        for (const char& c : path) {
            if (c == 'N') {
                p.first +=1 ;
            }
            if (c == 'S') {
                p.first -= 1;
            }
            if (c == 'E') {
                p.second += 1;
            }
            if (c == 'W') {
                p.second -= 1;
            }
            if (s.find(p) != s.end()) {
                return true;
            }
            s.insert(p);
        }
        return false;
        
    }
};