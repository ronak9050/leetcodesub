class MyQueue {
    stack<int> st1,st2;
public:
    MyQueue() {
        while(st1.size()) st1.pop();
        while(st2.size()) st2.pop();
    }
    
    void push(int x) {
        while(st1.size()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int ans=st1.top();
        st1.pop();
        return ans;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return (st1.size()+st2.size())==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */