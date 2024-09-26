class MyCalendar {
    set<pair<int,int>> st;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=st.lower_bound({start,end});
        if(it==st.end() || it->second>=end){
            st.insert({end,start});
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */