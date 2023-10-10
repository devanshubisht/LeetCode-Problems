class SORTracker {
public:
    struct cmp{
        bool operator() (pair<string, int> a, pair<string, int> b) const{
            if(a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        }
    };
    
    set<pair<string, int>, cmp> s;
    set<pair<string, int>>::iterator it;
    
    SORTracker() {
        s.insert({"", INT_MIN});
        it = s.begin();
    }

    void add(string name, int score) {
        auto [_name, _score] = *it;
        if((_score < score) || (score == _score && _name > name)){
            s.insert({name, score});
            --it;
        } 
        else s.insert({name, score});
    }
    
    string get() {
        string ans = it++->first;
        return ans;
    }
};;

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */