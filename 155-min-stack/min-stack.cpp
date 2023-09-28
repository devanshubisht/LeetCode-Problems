class MinStack {
public:
    std::stack<int> st;
    std::stack<int> mins;

    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (mins.empty()) {
            mins.push(val);
        } else if (mins.top()>= val) {
            mins.push(val);
        }
    }
    
    void pop() {
        if (mins.empty()) {
            return;
        }
        int val = st.top();
        st.pop();
        if (val == mins.top()) {
            mins.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */