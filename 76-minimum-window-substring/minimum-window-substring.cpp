class Solution {
public:
    string minWindow(string s, string t) {
        int st=-1,en=1e9,n=s.size(),i=0,j=0,req=0,cur=0;
        vector<int> tct(60,0),ct(60,0);
        for(auto &e:t) tct[e-'A']++;
        for(auto &e:tct) if(e) req++;
        while(i<n){
            ct[s[i]-'A']++;
            if(ct[s[i]-'A']==tct[s[i]-'A']) cur++;
            i++;
            
            while(j<n && ct[s[j]-'A']>tct[s[j]-'A']){
                ct[s[j]-'A']--;
                j++;
            }

            if(req==cur){
                if(en-st>i-j && i>j) st=j,en=i;
            }
            // if(f){
                
            // }
        }
        string ans;
        if(st==-1) return ans;
        for(i=st; i<en; i++) ans.push_back(s[i]);
        return ans;
    }
};