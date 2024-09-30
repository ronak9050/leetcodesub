class CustomStack {
    vector<int> a;
    int n,i=0;
public:
    CustomStack(int maxSize) {
        n=maxSize;
        a.resize(n,-1);
    }
    
    void push(int x) {
        if(i<n) {
            a[i]=x;
            i++;
        }
    }
    
    int pop() {
        if(i) {
            i--;
            return a[i];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int j=0; j<min(n,k); j++) a[j]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */