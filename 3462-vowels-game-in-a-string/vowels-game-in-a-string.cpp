class Solution {
public:
    bool doesAliceWin(string s) {
        vector<int> vis(26,0);
        vis[0]=1;vis[4]=1;vis[8]=1;vis[14]=1;vis[20]=1;
        for(auto &e:s) if(vis[e-'a']) return 1;
        return 0;
    }
};