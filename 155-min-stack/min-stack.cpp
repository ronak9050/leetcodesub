class MinStack {
    stack<int> primary;  // Primary stack to store all elements
    stack<int> minStack; // Stack to store the minimum elements
public:
    MinStack() {
        // Fast I/O setup (can be omitted if not using input/output in competitive programming)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    void push(int val) {
        primary.push(val);  // Push value onto the primary stack
        // Push onto minStack if it's empty or the new value is <= current min
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (primary.empty()) return;  // No operation if primary stack is empty
        int topValue = primary.top(); // Get the top value
        primary.pop();                // Pop from primary stack
        // If the top value is the same as the top of minStack, pop from minStack
        if (!minStack.empty() && topValue == minStack.top()) {
            minStack.pop();
        }
    }
    
    int top() {
        return primary.top(); // Return the top value of the primary stack
    }
    
    int getMin() {
        return minStack.top(); // Return the top value of the minStack (current minimum)
    }
};