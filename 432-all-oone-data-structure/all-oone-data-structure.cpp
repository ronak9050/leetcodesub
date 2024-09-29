class AllOne {
    unordered_map<string,int> mp;
    set<pair<int,string>> st;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int num=mp[key];
        st.erase({num,key});
        mp[key]++;
        st.insert({num+1,key});
    }
    
    void dec(string key) {
        int num=mp[key];
        st.erase({num,key});
        mp[key]--;
        if(num-1)st.insert({num-1,key});
    }
    
    string getMaxKey() {
        if(st.empty()) return "";
        auto it=st.end();
        it--;
        return it->second;
    }
    
    string getMinKey() {
        if(st.empty()) return "";
        auto it=st.begin();
        return it->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */