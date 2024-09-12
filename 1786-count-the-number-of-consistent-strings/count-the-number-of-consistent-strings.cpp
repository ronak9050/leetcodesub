class Solution {
public:
    int countConsistentStrings(string b, vector<string>& a) {
        vector<int> mn(26,0);
        for(auto &e:b) mn[e-'a']++;
        int ans=0;
        for(auto &e:a){
            vector<int> cur(26,0);
            for(auto f:e) cur[f-'a']++;
            int f=1;
            for(int i=0; i<26; i++) if(cur[i] && mn[i]==0) f=0;
            if(f) ans++;
        }
        return ans;
    }
};