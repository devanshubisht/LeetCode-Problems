class TimeMap {
public:
    map<int,unordered_map<string,string>> m;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[timestamp].insert({key,value});   
    }
    
    string get(string key, int timestamp) {
        auto it = m.upper_bound(timestamp);
        if (it == m.end() || it->first > timestamp) {
            it--;
            while (it != m.begin() && !it->second.count(key) > 0) {
                it--;
            }
            if (it->first <= timestamp && it->second.count(key) > 0) {
                return it->second[key];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */