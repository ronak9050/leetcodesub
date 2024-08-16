class Solution {
public:
    bool doesAliceWin(string s) {
        map<char,int> mp={{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
        int ct=0;
        for(auto &e:s) if(mp[e]) ct++;
        if(ct) return 1;
        return 0;
    }
};