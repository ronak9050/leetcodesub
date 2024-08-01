class Solution {
public:
    string minWindow(string s, string t) {
        int st=-1,en=1e9,n=s.size(),i=0,j=0;
        vector<int> tct(60,0),ct(60,0);
        for(auto &e:t) tct[e-'A']++;
        while(i<n){
            ct[s[i]-'A']++;
            i++;
            while(j<n && ct[s[j]-'A']>tct[s[j]-'A']){
                ct[s[j]-'A']--;
                j++;
            }
            int f=1;
            for(int k=0; k<60; k++) if(ct[k]<tct[k]) f=0;
            if(f){
                if(en-st>i-j && i>j) st=j,en=i;
            }
        }
        string ans;
        if(st==-1) return ans;
        for(i=st; i<en; i++) ans.push_back(s[i]);
        return ans;
    }
};