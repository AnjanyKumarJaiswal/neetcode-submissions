class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
        if(minStack.empty()){
            minStack.push_back(val);
        } else {
            minStack.push_back(min(val,minStack.back()));
        }
        
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */