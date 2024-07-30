class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int p) {
        int ct=1;
        while(st.size() && st.top().first<=p){
            ct+=st.top().second;
            st.pop();
        }
        st.push({p,ct});
        return ct;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */