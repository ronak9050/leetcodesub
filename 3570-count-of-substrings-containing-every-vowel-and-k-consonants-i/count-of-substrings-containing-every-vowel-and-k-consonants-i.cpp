

class Solution {
public:
    
    int countOfSubstrings(string s, int req) {
        int n=s.size(),ans=0;
        vector<int> mp(26,0);
        mp[0]=1;mp[4]=1;mp[8]=1;mp[14]=1;mp[20]=1;
        for(int i=0; i<n; i++){
            vector<int> cur(26,0);
            for(int j=i; j<n; j++){
                cur[s[j]-'a']++;
                int f=1,tot=0;
                for(int k=0; k<26; k++){
                    if(mp[k] && !cur[k]) f=0;
                    if(!mp[k]) tot+=cur[k];
                }
                if(tot!=req) f=0;
                if(f) ans++;
            }
        }
        
        return ans;
    }
};