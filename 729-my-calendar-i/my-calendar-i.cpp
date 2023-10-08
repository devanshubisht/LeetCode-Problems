class MyCalendar {
public:
    map<int,int> m;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if (m.count(start) > 0) return false;
        m[start] = end;
        auto it = m.find(start);
        if (it != m.begin()) {
            it--;
            if (it->second > start || it->first== start ) {
                m.erase(start);
                return false;
            }
            it++;
        }
        it++;
        if (it != m.end()) {
            if (it->first < end || it->first == start) {
                m.erase(start);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */