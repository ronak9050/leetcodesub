class MinStack {
    stack<int> st1,st2,st3;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        while(st2.size() && st2.top()<val){
            st3.push(st2.top());
            st2.pop();
        }
        st2.push(val);
        while(st3.size()){
            st2.push(st3.top());
            st3.pop();
        }
    }
    
    void pop() {
        int ans=st1.top();
        st1.pop();
        while(st2.top()!=ans){
            st3.push(st2.top());
            st2.pop();
        }
        st2.pop();
        while(st3.size()){
            st2.push(st3.top());
            st3.pop();
        }
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
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