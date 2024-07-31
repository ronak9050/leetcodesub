class Solution {
public:
    int fnmx(vector<int>&ct){
        int ans=0;
        for(auto &e:ct) ans=max(ans,e);
        return ans;
    }
    int characterReplacement(string s, int k) {
        vector<int> ct(26,0);
        int ans=0,i=0,j=0,n=s.size();
        while(i<n){
            ct[s[i]-'A']++;
            i++;
            int mx=fnmx(ct);
            while(i-j-mx>k){
                ct[s[j]-'A']--;
                mx=fnmx(ct);
                j++;
            }
            ans=max(ans,i-j);
        }
        return ans;
    }
};