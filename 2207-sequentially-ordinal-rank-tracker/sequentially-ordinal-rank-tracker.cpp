class SORTracker {
public:
    std::set<pair<int,string>> s;
    set<pair<int,string>>::iterator it;
    SORTracker() {
    }
    
    void add(string name, int score) {
        auto it1 = s.insert({-score,name}).first;
        if (s.size() == 1) {
            it = s.begin();
            return;
        } 
        if (*it1  < *it) {
            it--;
        }
    }
    
    string get() {
        string val = it->second;
        it++;
        return val;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */