class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        while(q1.size()) q1.pop();
        while(q2.size()) q2.pop();
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q1.pop();
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        int last;
        while(q1.size()){
            last=q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        return last;
    }
    
    bool empty() {
        return (!q1.size());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */