class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        int mini;
        if (s.empty()) {
            mini = val;
        } else {
            mini = std::min(val, s.top().second);
        }
        s.push({val, mini});
    }
    
    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }
    
    int top() {
        if (!s.empty()) {
            return s.top().first;
        }
        return 0;
    }
    
    int getMin() {
        if (!s.empty()) 
         return s.top().second;
         return 0;
    }
    
private:
    std::stack<std::pair<int, int>> s;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */