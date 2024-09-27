class MyCalendarThree {
    map<int,int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int st, int end) {
        mp[st]++;
        mp[end]--;
        int ans=0,ct=0;
        for(auto &e:mp){
            ct+=e.second;
            ans=max(ans,ct);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */