class Solution {
public:
    int minimumPushes(string s) {
        vector<int> ct(26,0);
        for(auto &e:s) ct[e-'a']++;
        sort(ct.begin(),ct.end(),greater<int>());
        int ans=0;
        for(int i=0; i<26; i++){
            ans+=ct[i]*(i/8+1);
        }
        return ans;
    }
};