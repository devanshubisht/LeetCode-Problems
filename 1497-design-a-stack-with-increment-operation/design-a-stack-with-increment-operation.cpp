class CustomStack {
public:
    vector<int> vec;
    int max_size = 0;
    CustomStack(int maxSize) {
        this->max_size = maxSize;
    }
    
    void push(int x) {
        if (vec.size() >= this->max_size) {
            return;
        }
        vec.push_back(x);
    }
    
    int pop() {
        if (vec.size() == 0) {
            return -1;
        }
        int x = vec.back();
        vec.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        int size = vec.size();
        if (k < vec.size()) {
            size = k;
        }
        for (int i = 0 ; i < size ; i++ ) {
            vec[i]+= val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */