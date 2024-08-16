class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_map <char,int> mp={{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
        int ct=0;
        for(auto &e:s) if(mp[e]) return 1;
        return 0;
    }
};